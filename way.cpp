#include "way.h"
using namespace std;

way::way()
{
       valid = false;
       dirty = false;
       tag = 0;
       next = nullptr;
       prev = nullptr;
}

way::way(way* Prev,way* Next)
{
       valid = false;
       dirty = false;
       tag = 0;
       next = Next;
       prev = Prev;
}

int way::promote(way** head)
{
        if(prev!=nullptr)
        {
                if(next!=nullptr)
                {
                        next->prev = prev;
                }
                prev->next = next;
                prev = nullptr;
                next = *head;
                (*head)->prev = this;
                *head = this;
        }
        return 0;
}

int way::read(way** head, ull address)
{
        way* node = *head;
        while(node!=nullptr)
        {
                if(node->valid && node->tag==address)
                {
                        node->promote(head);
                        return 0;
                }
                else
                {
                        node=node->next;
                }
        }
        return -1;
}

int way::write(way** head, ull address)
{
        way* node = *head;
        while(node!=nullptr)
        {
                if(node->valid && node->tag==address)
                {
                        node->dirty = true;
                        node->promote(head);
                        return 0;
                }
                else
                {
                        node=node->next;
                }
        }
        return -1;
}

k_ret way::poll(way** head)
{
        k_ret retval;
        way* node = *head;
        while(node->next!=nullptr)
        {
                node=node->next;
        }
        retval.address=node->tag;
        retval.valid=node->valid;
        retval.dirty=node->dirty;
        return retval;
}

int way::fill(way** head, ull address)
{
        way* node = *head;
        while(node->next!=nullptr)
        {
                node=node->next;
        }
        node->tag=address;
        node->valid=true;
        node->dirty=false;
        node->promote(head);
        return 0;
}

int way::flush(way** head)
{
        way* node=*head;
        while(node!=nullptr)
        {
                node->valid=false;
                node->dirty=false;
                node=node->next;
        }
        return 0;
}
