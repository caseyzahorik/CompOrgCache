#!/bin/bash

#g++ -Wall -static -O3 --std=c++11 main.cpp processor.cpp l1cache.cpp l2cache.cpp memory.cpp way.cpp watcher.cpp

#mv a.out testing/

zcat testing/traces-long/omnetpp.gz | testing/a.out config/All-2way.txt             > testing/output/omnetpp.All-2way &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/All-4way.txt             > testing/output/omnetpp.All-4way &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/omnetpp.All-FA-L2Big &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/All-FA.txt               > testing/output/omnetpp.All-FA &
wait
zcat testing/traces-long/omnetpp.gz | testing/a.out config/Default.txt              > testing/output/omnetpp.default &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L1-2way.txt              > testing/output/omnetpp.L1-2way &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L1-8way.txt              > testing/output/omnetpp.L1-8way &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L1-small-4way.txt        > testing/output/omnetpp.L1-small-4way &
wait
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L1-small.txt             > testing/output/omnetpp.L1-small &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L2-4way.txt              > testing/output/omnetpp.L2-4way &
zcat testing/traces-long/omnetpp.gz | testing/a.out config/L2-Big.txt               > testing/output/omnetpp.L2-Big &
