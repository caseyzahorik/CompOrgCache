#!/bin/bash
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.All-2way.txt             > testing/output/sjeng4.All-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.All-4way.txt             > testing/output/sjeng4.All-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.All-FA-L2Big.txt         > testing/output/sjeng4.All-FA-L2Big &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.All-FA.txt               > testing/output/sjeng4.All-FA &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.Default.txt              > testing/output/sjeng4.default &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L1-2way.txt              > testing/output/sjeng4.L1-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L1-8way.txt              > testing/output/sjeng4.L1-8way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L1-small-4way.txt        > testing/output/sjeng4.L1-small-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L1-small.txt             > testing/output/sjeng4.L1-small &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L2-4way.txt              > testing/output/sjeng4.L2-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/sjeng.gz | testing/a.out config/sjeng4.L2-Big.txt               > testing/output/sjeng4.L2-Big &
wait

