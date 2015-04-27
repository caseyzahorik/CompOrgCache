#include "l1cache.h"
using namespace std;

l1cache::l1cache(int block,int cache,int assoc,int hit,int miss,l2cache* l2,watcher* watch)
{
        Watcher = watch;
        blockSize = block;
        cacheSize = cache;
        associativity = assoc;
        hitTime = hit;
        missTime = miss;
        L2 = l2;
        sets = (cacheSize/(associativity*blockSize));
        blockSizeMask = ~((ull)blockSize-1);
        blockShift = std::log2(blockSize);
        indexMask = ((ull)sets-1);
        indexShift = std::log2(sets);
        set = new way*[sets];
        way* temp1=nullptr;
        way* temp2=nullptr;
        for(int i=0;i<sets;i++)
        {
                set[i] = new way();
                temp1 = set[i];
                for(int j=1;j<associativity;j++)
                {
                        temp2 = new way(temp1,nullptr);
                        temp1->next=temp2;
                        temp1 = temp2;
                }
        }

        hitcount=0;
        misscount=0;
        requests=0;
        kickouts=0;
        dirty=0;
        transfer=0;
        flush=0;
}

ull l1cache::read(ull address)
{
        requests++;
        ull time=0;
        ull set_address=address&blockSizeMask;
        ull index = address>>(blockShift);
        index = index&indexMask;
        //debug
        //printf("    index = 0x%llx, tag =  0x%llx",index,address>>(blockShift+indexShift));
        //debug
        if(set[index]->read(&set[index],set_address))
        {//note that read returns 0 on success
                misscount++;
                transfer++;
                k_ret writeback = set[index]->poll(&set[index]);
                //debug
                //printf("  MISS\n");
                //printf("Add L1x miss time (+ 1)\n");
                //debug
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                                //debug
                                //printf("Doing dirty writeback\n");
                                //debug
                                time+=L2->write(writeback.address,blockSize);
                        }
                        kickouts++;
                }
                time+=missTime+L2->read(address,blockSize);
                //debug
                //printf("Add L1x hit replay time (+ 1)\n");
                //debug
                set[index]->fill(&set[index],set_address);
        }
        else
        {
                hitcount++;
                //debug
                //printf("  HIT\n");
                //printf("Add L1x hit time (+ 1)\n");
                //debug
        }
        return time+hitTime;
}

ull l1cache::write(ull address)
{
        requests++;
        ull time=0;
        ull set_address=address&blockSizeMask;
        ull index = address>>(blockShift);
        index = index&indexMask;
        //debug
        //printf("    index = 0x%llx, tag =  0x%llx",index,address>>(blockShift+indexShift));
        //debug
        if(set[index]->write(&set[index],set_address))
        {//note that read returns 0 on success
                misscount++;
                transfer++;
                k_ret writeback = set[index]->poll(&set[index]);
                //debug
                //printf("  MISS\n");
                //printf("Add L1x miss time (+ 1)\n");
                //debug
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                                time+=L2->write(writeback.address,blockSize);
                                //debug
                                //printf("Doing dirty writeback\n");
                                //debug
                        }
                        kickouts++;
                }
                time+=missTime+L2->read(address,blockSize);
                //debug
                //printf("Add L1x hit replay time (+ 1)\n");
                //debug
                set[index]->fill(&set[index],set_address);
                set[index]->write(&set[index],set_address);
        }
        else
        {
                hitcount++;
                //debug
                //printf("  HIT\n");
                //printf("Add L1x hit time (+ 1)\n");
                //debug
        }
        return time+hitTime;
}

ull l1cache::flushAll()
{
        ull time=0;
        for(int i=0;i<sets;i++)
        {
                way* head = set[i];
                while(head!=nullptr)
                {
                        if(head->dirty&&head->valid)
                        {
                                flush++;
                                transfer++;
                                time+=L2->write(head->tag,blockSize);
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
        return time;
}
