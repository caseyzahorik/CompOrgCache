#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "types.h"
#include "way.h"
#include "watcher.h"
#include "memory.h"
#include "l2cache.h"
#include "l1cache.h"
#include "processor.h"

using namespace std;

int main(int argc, char** argv)
{
        //default memory parameters
        int send = 10;
        int ready = 30;
        int trans = 15;
        int bus = 8;
        //default l2 parameters
        int l2block = 64;
        int l2size = 32768;
        int l2assoc = 1;
        int l2hit = 5;
        int l2miss = 7;
        int l2trans = 5;
        int l2bus = 16;
        //default l1 parameters
        int l1block = 32;
        int l1size = 8192;
        int l1assoc = 1;
        int l1hit = 1;
        int l1miss = 1;

        cout<<argc<<endl;
        if(argc==2)
        {

                cout<<"test5"<<endl;
                ifstream config;
                config.open(string(argv[1]));
                cout<<"test6"<<endl;
                if(config.is_open())
                {
                        cout<<"test7"<<endl;
                        int c_args[16];
                        string temp;
                        for(int i=0;i<15;i++)
                        {
                                getline(config,temp);
                                cout<<"test8"<<endl;
                                c_args[i] = stoi(temp,nullptr,10);
                        }
                        send    = c_args[0];
                        ready   = c_args[1];
                        trans   = c_args[2];
                        bus     = c_args[3];
                        l2block = c_args[4];
                        l2size  = c_args[5];
                        l2assoc = c_args[6];
                        l2hit   = c_args[7];
                        l2miss  = c_args[8];
                        l2trans = c_args[9];
                        l2bus   = c_args[10];
                        l1block = c_args[11];
                        l1size  = c_args[12];
                        l1assoc = c_args[13];
                        l1hit   = c_args[14];
                        l1miss  = c_args[15];
                        cout<<"test9"<<endl;
                        config.close();
                        cout<<"test10"<<endl;
                }
                else
                {
                        cout<<"failed to open config file"<<endl;
                        return 0;
                }
        }

        //main object declarations
        watcher Watcher;
        cout<<"test11"<<endl;
        memory Disk(send,ready,trans,bus,&Watcher);
        cout<<"test12"<<endl;
        l2cache L2(l2block,l2size,l2assoc,l2hit,l2miss,l2trans,l2bus,&Disk,&Watcher);
        cout<<"test13"<<endl;
        l1cache Dcache(l1block,l1size,l1assoc,l1hit,l1miss,&L2,&Watcher);
        cout<<"test14"<<endl;
        l1cache Icache(l1block,l1size,l1assoc,l1hit,l1miss,&L2,&Watcher);
        cout<<"test15"<<endl;
        processor CPU(&Icache,&Dcache,&Watcher);
        cout<<"test1"<<endl;

        //dcache info
        Watcher.DcacheSize = l1size;
        Watcher.DcacheWays = l1assoc;
        Watcher.DcacheBlock = l1block;
        //icache info
        Watcher.IcacheSize = l1size;
        Watcher.IcacheWays = l1assoc;
        Watcher.IcacheBlock = l1block;
        //l2cache info
        Watcher.L2Size = l2size;
        Watcher.L2Ways = l2assoc;
        Watcher.L2Block = l2block;
        //main mem info
        Watcher.ReadyTime = ready;
        Watcher.ChunkSize = bus;
        Watcher.ChunkTime = trans;
        cout<<"test2"<<endl;

        //read in from stdin from gcat
        char op;
        ull address;
        uint bytes;
        ull timeTotal = 0;
        int flush = 0;
        ull temp=0;
        while(scanf("%c %Lx %d\n", &op, &address, &bytes) == 3)
        {
                if(op=='I') flush++;
                if(flush==380000)
                {
                        flush=0;
                        temp += Icache.flushAll();
                        temp += Dcache.flushAll();
                        temp += L2.flushAll();
                        Watcher.FlushTime +=temp;
                        Watcher.ExecuteTime +=temp;
                        Watcher.Flushes++;
                        Watcher.Invalidates++;
                        temp=0;
                }
                timeTotal += CPU.decode(op, address, bytes);
                cout<<"test3"<<endl;
        }
        //icache specifics
        Watcher.iHitCount = Icache.hitcount;
        Watcher.iMissCount = Icache.misscount;
        Watcher.iRequests = Icache.requests;
        Watcher.iKickouts = Icache.kickouts;
        Watcher.iDirtyKickout = Icache.dirty;
        Watcher.iTransKickout = Icache.transfer;
        Watcher.iFlushKickout = Icache.flush;
        //dcache specifics
        Watcher.dHitCount = Dcache.hitcount;
        Watcher.dMissCount = Dcache.misscount;
        Watcher.dRequests = Dcache.requests;
        Watcher.dKickouts = Dcache.kickouts;
        Watcher.dDirtyKickout = Dcache.dirty;
        Watcher.dTransKickout = Dcache.transfer;
        Watcher.dFlushKickout = Dcache.flush;
        //l2 specifics
        Watcher.LHitCount = L2.hitcount;
        Watcher.LMissCount = L2.misscount;
        Watcher.LRequests = L2.requests;
        Watcher.LKickouts = L2.kickouts;
        Watcher.LDirtyKickout = L2.dirty;
        Watcher.LTransKickout = L2.transfer;
        Watcher.LFlushKickout = L2.flush;
        Watcher.print();
        cout<<"test4"<<endl;
        return 0;
};
