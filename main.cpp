#include "manager.h"

int main(int argc, char* argv[])
{
        //default memory parameters
        int send = 10;
        int ready = 30;
        int trans = 15;
        int bus = 8;
        //default l2 parameters
        int l2block = 64;
        int l2cache = 32768;
        int l2assoc = 1;
        int l2hit = 5;
        int l2miss = 7;
        int l2trans = 5;
        int l2bus = 16;
        //default l1 parameters
        int l1block = 32;
        int l1cache = 8192;
        int l1assoc = 1;
        int l1hit = 1;
        int l1miss = 1;

        //put in config file stuff here!
        if(argv[1] == NULL)
        {
                printf("you done goofed up the input\nrun as follows: [zcat/cat] [trace file name/location] | [simulator] [config file name/location]");
                return 0;
        }
        FILE * configFile = fopen(argv[1], "r");
        //then read things in... not sure yet what the format is though so this will have to be completed later
        fclose(configFile);


        watcher Watcher;
        memory Disk(send,ready,trans,bus,Watcher);
        l2cache L2(l2block,l2cache,l2assoc,l2hit,l2miss,l2trans,l2bus,Disk,Watcher);
        l1cache Dcache(l1block,l1cache,l1assoc,l1hit,l1miss,l2,Watcher);
        l1cache Icache(l1block,l1cache,l1assoc,l1hit,l1miss,l2,Watcher);
        processor CPU(Icache,Dcache,Watcher);

        //read in from stdin from gcat
        char op;
        ull address;
        uint bytes;
        ull timeTotal = 0;
        while(scanf("%c %Lx %d\n", &op, &address, &bytes) == 3)
        {
        	timeTotal += processor::decode(op, address, bytes);
        }
}
