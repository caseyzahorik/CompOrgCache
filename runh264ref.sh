#!/bin/bash
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/All-2way.txt             > testing/output/h264ref.All-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/All-4way.txt             > testing/output/h264ref.All-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/h264ref.All-FA-L2Big &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/All-FA.txt               > testing/output/h264ref.All-FA &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/Default.txt              > testing/output/h264ref.default &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L1-2way.txt              > testing/output/h264ref.L1-2way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L1-8way.txt              > testing/output/h264ref.L1-8way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L1-small-4way.txt        > testing/output/h264ref.L1-small-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L1-small.txt             > testing/output/h264ref.L1-small &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L2-4way.txt              > testing/output/h264ref.L2-4way &
zcat /projects/caza9241/ecen4593-sp15/traces-long/h264ref.gz | testing/a.out config/L2-Big.txt               > testing/output/h264ref.L2-Big &
wait

