#include "l2cache.h"

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
}

l2cache::~l2cache()
{
        way* head=nullptr;
        for(int i=0;i<sets;i++)
        {
                head = set[i]
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
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->read(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+mainMemory->transferData(blockSize);
                ull writeback = set[index]->fill(&set[index],address)
                if(writeback<ULLONG_MAX)
                {
                        time+=mainMemory->transferData(blockSize);
                }
        }
        return time+hitTime+transferTime*block/busWidth;
}

ull l2cache::write(ull address,int block)
{
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+mainMemory->transferData(blockSize);
                ull writeback = set[index]->fill(&set[index],address)
                if(writeback<ULLONG_MAX)
                {
                        time+=mainMemory->transferData(blockSize);
                }
        }
        return time+hitTime+transferTime*block/busWidth;
}

ull l2cache::flushAll()
{
        ull time;
        for(int i=0;i<sets;i++)
        {
                way* head = set[i];
                while(head!=nullptr)
                {
                        if(head->dirty)
                        {
                                time = mainMemory->transferData(blockSize);
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
        return time;
}
