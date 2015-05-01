#!/bin/bash
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/All-2way.txt             > testing/output/omnetpp.All-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/All-4way.txt             > testing/output/omnetpp.All-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/omnetpp.All-FA-L2Big &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/All-FA.txt               > testing/output/omnetpp.All-FA &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/Default.txt              > testing/output/omnetpp.default &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L1-2way.txt              > testing/output/omnetpp.L1-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L1-8way.txt              > testing/output/omnetpp.L1-8way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L1-small-4way.txt        > testing/output/omnetpp.L1-small-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L1-small.txt             > testing/output/omnetpp.L1-small &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L2-4way.txt              > testing/output/omnetpp.L2-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/omnetpp.gz | testing/a.out config/L2-Big.txt               > testing/output/omnetpp.L2-Big &
wait

