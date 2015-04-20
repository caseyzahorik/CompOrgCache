#include "l1cache.h"

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

        hitcount=0;
        misscount=0;
        requests=0;
        kickouts=0;
        dirty=0;
        transfer=0;
        flush=0;
}

l1cache::~l1cache()
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

ull l1cache::read(ull address)
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
                ull writeback = set[index]->fill(&set[index],address)
                if(writeback<ULLONG_MAX)
                {
                        time+=l2->write(writeback,blockSize);
                }
        }
        return time+hitTime;
}

ull l1cache::write(ull address)
{
        ull time=0;
        address=address&blockSizeMask;
        int index = address>>indexShift;
        index&=indexMask;
        if(set[index]->write(&set[index],address))
        {//note that read returns 0 on success
                time+=missTime+L2->read(address,blockSize);
                ull writeback = set[index]->fill(&set[index],address)
                if(writeback<ULLONG_MAX)
                {
                        time+=l2->write(writeback,blockSize);
                }
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
                        if(head->dirty)
                        {
                                time+=L2->write(head->tag,blockSize);
                        }
                        head=head->next;
                }
                set[i]->flush(&set[i]);
        }
        return time;
}
