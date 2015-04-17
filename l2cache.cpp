#include "l2cache.h"

//l2cache::l2cache()
//{
//        blockSize = 64;
//        cacheSize = 32768;
//        associativity = 1;
//        hitTime = 5;
//        missTime = 7;
//        transferTime = 5;
//        busWidth = 16;
//        mainMemory = nullptr;
//        sets = (cacheSize/blockSize);
//        set = new way*[sets];
//        for(int i=0;i<sets;i++)
//        {
//                set[i] = new way();
//        }
//}
//
//l2cache::l2cache(memory* Memory)
//{
//        blockSize = 64;
//        cacheSize = 32768;
//        associativity = 1;
//        hitTime = 5;
//        missTime = 7;
//        transferTime = 5;
//        busWidth = 16;
//        mainMemory = Memory;
//        sets = (cacheSize/blockSize);
//        set = new way*[sets];
//        for(int i=0;i<sets;i++)
//        {
//                set[i] = new way();
//        }
//}
//these functions are also probably unnecessary, so i'v commented
//them out for the time being

l2cache::l2cache(int block,int cache,int assoc,int hit,int miss,int trans,int bus,memory* Memory)
{
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

int l2cache::BlockSize(){return blockSize;}
int l2cache::CacheSize(){return cacheSize;}
int l2cache::Associativity(){return associativity;}
int l2cache::HitTime(){return hitTime;}
int l2cache::MissTime(){return missTime;}
int l2cache::TransferTime(){return transferTime;}
int l2cache::BusWidth(){return busWidth;}

int l2cache::read(ull address,int block)
{
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->read(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+mainMemory->transferData(blockSize);
        }
        return time+=hitTime+transferTime*block/busWidth;
}

int l2cache::write(ull address,int block)
{
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+mainMemory->transferData(blockSize);
        }
        return hitTime+transferTime*block/busWidth;
}

int l2cache::flushAll()
{
        for(int i=0;i<sets;i++)
        {
                way* head = set[i];
                while(head!=nullptr)
                {
                        if(head->dirty)
                        {
                                int time = mainMemory->transferData(blockSize);
                                //DO SOMETHING HERE
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
}
