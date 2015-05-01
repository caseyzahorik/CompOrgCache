#!/bin/bash
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/All-2way.txt             > testing/output/bzip2.All-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/All-4way.txt             > testing/output/bzip2.All-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/bzip2.All-FA-L2Big &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/All-FA.txt               > testing/output/bzip2.All-FA &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/Default.txt              > testing/output/bzip2.default &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L1-2way.txt              > testing/output/bzip2.L1-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L1-8way.txt              > testing/output/bzip2.L1-8way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L1-small-4way.txt        > testing/output/bzip2.L1-small-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L1-small.txt             > testing/output/bzip2.L1-small &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L2-4way.txt              > testing/output/bzip2.L2-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/bzip2.gz | testing/a.out config/L2-Big.txt               > testing/output/bzip2.L2-Big &
wait
