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

way::way(way* prev,way* next)
{
       valid = false;
       dirty = false;
       tag = 0;
       next = next;
       prev = prev;
}

int way::promote(way** head)
{
        if(this->prev!=nullptr)
        {
                if(this->next!=nullptr)
                {
                        this->next->prev = this->prev;
                }
                this->prev->next = this->next;
                this->prev = nullptr;
                this->next = *head;
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
                if(node->valid&&node->tag==address)
                {
                        if(node!=*head)
                        {
                                node->promote(head);
                        }
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
                if(node->valid&&node->tag==address)
                {
                        if(node!=*head)
                        {
                                node->promote(head);
                        }
                        node->dirty = true;
                        return 0;
                }
                else
                {
                        node=node->next;
                }
        }
        return -1;
}

k_ret way::fill(way** head, ull address)
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
        node->tag=address;
        node->valid=true;
        node->dirty=false;
        node->promote(head);
        return retval;
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
