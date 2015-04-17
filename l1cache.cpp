#include "l1cache.h"

//l1cache::l1cache()
//{
//        blockSize = 32;
//        cacheSize = 8192;
//        associativity = 1;
//        hitTime = 1;
//        missTime = 1;
//        L2 = nullptr;
//        sets = (cacheSize/blockSize);
//        set = new way*[sets];
//        for(int i=0;i<sets;i++)
//        {
//                set[i] = new way();
//        }
//}
//
//l1cache::l1cache(l2cache* l2)
//{
//        blockSize = 32;
//        cacheSize = 8192;
//        associativity = 1;
//        hitTime = 1;
//        missTime = 1;
//        L2 = l2;
//        sets = (cacheSize/blockSize);
//        set = new way*[sets];
//        for(int i=0;i<sets;i++)
//        {
//                set[i] = new way();
//        }
//}
//these functions taken out for the time being, not necessary
//to be deleted later when this is confirmed

l1cache::l1cache(int block,int cache,int assoc,int hit,int miss,l2cache* l2)
{
        blockSize = block;
        cacheSize = cache;
        associativity = assoc;
        hitTime = hit;
        missTime = miss;
        L2 = l2;
        sets = (cacheSize/(associativity*blockSize));
        blockSizeMask = ~((ull)block-1);
        indexMask = ~((ull)sets-1);
        indexShift = std::log2(sets);
        set = new way*[sets];
        way* temp = nullptr;
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

int l1cache::BlockSize()
{
        return blockSize;
}

int l1cache::CacheSize()
{
        return cacheSize;
}

int l1cache::Associativity()
{
        return associativity;
}

int l1cache::HitTime()
{
        return hitTime;
}

int l1cache::MissTime()
{
        return missTime;
}

int l1cache::read(ull address)
{
//at this point, the address is now aligned to 4 byte boundaries
//from here, we align it to blockSize boundaries, i guess
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->read(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+L2->read(address,blockSize);
        }
        return time+hitTime;
}

int l1cache::write(ull address)
{
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+L2->write(address,blockSize);
        }
        return time+hitTime;
}

int l1cache::flushAll()
{
        for(int i=0;i<sets;i++)
        {
                way* head = set[i];
                while(head!=nullptr)
                {
                        if(head->dirty)
                        {
                                int time = L2->write(head->tag);
                                //DO SOMETHING HERE
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
}
