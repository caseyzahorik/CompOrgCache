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
        sets = cacheSize/(blockSize*associativity);
        blockSizeMask = ~((ull)block-1);
        indexMask = ~((ull)sets-1);
        indexShift = std::log2(sets);
        set = new way* [sets];
        way* temp=nullptr;
        for(int i=0;i<sets;i++)
        {
                set[i] = new way();
                temp = set[i];
                for(int j=0;j<associativity;j++)
                {
                        temp = new way(temp,nullptr);
                        temp->prev->next=temp;
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

l2cache::~l2cache()
{
        way* head=nullptr;
        for(int i=0;i<sets;i++)
        {
                head = set[i];
                while(head->next!=nullptr)
                {
                        head=head->next;
                }
                while(head->prev!=nullptr)
                {
                        head=head->prev;
                        delete(head->next);
                }
                delete(head);
        }
        delete[] set;
}

ull l2cache::read(ull address,int block)
{
        requests++;
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->read(&set[index],address))
        {//note that read returns 0 on success
                misscount++;
                time+=missTime+mainMemory->transferData(blockSize);
                k_ret writeback = set[index]->fill(&set[index],address);
                transfer++;
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                        }
                        kickouts++;
                        time+=mainMemory->transferData(blockSize);
                }
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
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                misscount++;
                time+=missTime+mainMemory->transferData(blockSize);
                k_ret writeback = set[index]->fill(&set[index],address);
                transfer++;
                if(writeback.valid)
                {
                        if(writeback.dirty)
                        {
                                dirty++;
                        }
                        kickouts++;
                        time+=mainMemory->transferData(blockSize);
                }
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
                        if(head->dirty)
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
