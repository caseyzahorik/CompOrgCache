#include "l2cache.h"
using namespace std;

l2cache::l2cache(int block,int cache,int assoc,int hit,int miss,int trans,int bus,memory* Memory,watcher* watch)
{
        Watcher = watch;
        blockSize = block;
        cacheSize = cache;
        associativity = assoc;
        hitTime = hit;
        missTime = miss;
        transferTime = trans;
        busWidth = bus;
        mainMemory = Memory;
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

ull l2cache::read(ull address,int block)
{
        requests++;
        ull time=0;
        address=address&blockSizeMask;
        ull index = address>>(blockShift);
        index = index&indexMask;
        if(set[index]->read(&set[index],address))
        {//note that read returns 0 on success
                misscount++;
                transfer++;
                time+=missTime+mainMemory->transferData(blockSize);
                k_ret writeback = set[index]->fill(&set[index],address);
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                                time+=mainMemory->transferData(blockSize);
                        }
                        kickouts++;
                }
                set[index]->read(&set[index],address);
        }
        else
        {
                hitcount++;
        }
        return time+hitTime+transferTime*block/busWidth;
}

ull l2cache::write(ull address,int block)
{
        requests++;
        ull time=0;
        address=address&blockSizeMask;
        ull index = address>>(blockShift);
        index = index&indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                misscount++;
                transfer++;
                time+=missTime+mainMemory->transferData(blockSize);
                k_ret writeback = set[index]->fill(&set[index],address);
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                                time+=mainMemory->transferData(blockSize);
                        }
                        kickouts++;
                }
                set[index]->write(&set[index],address);
        }
        else
        {
                hitcount++;
        }
        return time+hitTime+transferTime*block/busWidth;
}

ull l2cache::flushAll()
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
                                time+=mainMemory->transferData(blockSize);
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
        return time;
}
