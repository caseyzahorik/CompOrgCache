#!/bin/bash
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/All-2way.txt             > testing/output/sjeng.All-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/All-4way.txt             > testing/output/sjeng.All-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/sjeng.All-FA-L2Big &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/All-FA.txt               > testing/output/sjeng.All-FA &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/Default.txt              > testing/output/sjeng.default &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L1-2way.txt              > testing/output/sjeng.L1-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L1-8way.txt              > testing/output/sjeng.L1-8way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L1-small-4way.txt        > testing/output/sjeng.L1-small-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L1-small.txt             > testing/output/sjeng.L1-small &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L2-4way.txt              > testing/output/sjeng.L2-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/L2-Big.txt               > testing/output/sjeng.L2-Big &
wait

