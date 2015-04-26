#!/bin/bash

g++ -Wall -static --std=c++11 main.cpp processor.cpp l1cache.cpp l2cache.cpp memory.cpp way.cpp watcher.cpp

mv a.out testing/

cat testing/traces-short/tr1 | testing/a.out config/All-2way.txt             > testing/output/tr1.All-2way &
cat testing/traces-short/tr1 | testing/a.out config/All-4way.txt             > testing/output/tr1.All-4way &
cat testing/traces-short/tr1 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr1.All-FA-L2Big &
cat testing/traces-short/tr1 | testing/a.out config/All-FA.txt               > testing/output/tr1.All-FA &
wait
cat testing/traces-short/tr1 | testing/a.out config/Default.txt              > testing/output/tr1.default &
cat testing/traces-short/tr1 | testing/a.out config/L1-2way.txt              > testing/output/tr1.L1-2way &
cat testing/traces-short/tr1 | testing/a.out config/L1-8way.txt              > testing/output/tr1.L1-8way &
cat testing/traces-short/tr1 | testing/a.out config/L1-small-4way.txt        > testing/output/tr1.L1-small-4way &
wait
cat testing/traces-short/tr1 | testing/a.out config/L1-small.txt             > testing/output/tr1.L1-small &
cat testing/traces-short/tr1 | testing/a.out config/L2-4way.txt              > testing/output/tr1.L2-4way &
cat testing/traces-short/tr1 | testing/a.out config/L2-Big.txt               > testing/output/tr1.L2-Big &
wait

cat testing/traces-short/tr2 | testing/a.out config/All-2way.txt             > testing/output/tr2.All-2way &
cat testing/traces-short/tr2 | testing/a.out config/All-4way.txt             > testing/output/tr2.All-4way &
cat testing/traces-short/tr2 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr2.All-FA-L2Big &
cat testing/traces-short/tr2 | testing/a.out config/All-FA.txt               > testing/output/tr2.All-FA &
wait
cat testing/traces-short/tr2 | testing/a.out config/Default.txt              > testing/output/tr2.default &
cat testing/traces-short/tr2 | testing/a.out config/L1-2way.txt              > testing/output/tr2.L1-2way &
cat testing/traces-short/tr2 | testing/a.out config/L1-8way.txt              > testing/output/tr2.L1-8way &
cat testing/traces-short/tr2 | testing/a.out config/L1-small-4way.txt        > testing/output/tr2.L1-small-4way &
wait
cat testing/traces-short/tr2 | testing/a.out config/L1-small.txt             > testing/output/tr2.L1-small &
cat testing/traces-short/tr2 | testing/a.out config/L2-4way.txt              > testing/output/tr2.L2-4way &
cat testing/traces-short/tr2 | testing/a.out config/L2-Big.txt               > testing/output/tr2.L2-Big &
wait

cat testing/traces-short/tr3 | testing/a.out config/All-2way.txt             > testing/output/tr3.Al3-2way &
cat testing/traces-short/tr3 | testing/a.out config/All-4way.txt             > testing/output/tr3.All-4way &
cat testing/traces-short/tr3 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr3.All-FA-L2Big &
cat testing/traces-short/tr3 | testing/a.out config/All-FA.txt               > testing/output/tr3.All-FA &
wait
cat testing/traces-short/tr3 | testing/a.out config/Default.txt              > testing/output/tr3.default &
cat testing/traces-short/tr3 | testing/a.out config/L1-2way.txt              > testing/output/tr3.L1-2way &
cat testing/traces-short/tr3 | testing/a.out config/L1-8way.txt              > testing/output/tr3.L1-8way &
cat testing/traces-short/tr3 | testing/a.out config/L1-small-4way.txt        > testing/output/tr3.L1-small-4way &
wait
cat testing/traces-short/tr3 | testing/a.out config/L1-small.txt             > testing/output/tr3.L1-small &
cat testing/traces-short/tr3 | testing/a.out config/L2-4way.txt              > testing/output/tr3.L2-4way &
cat testing/traces-short/tr3 | testing/a.out config/L2-Big.txt               > testing/output/tr3.L2-Big &
wait

cat testing/traces-short/tr4 | testing/a.out config/All-2way.txt             > testing/output/tr4.Al3-2way &
cat testing/traces-short/tr4 | testing/a.out config/All-4way.txt             > testing/output/tr4.All-4way &
cat testing/traces-short/tr4 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr4.All-FA-L2Big &
cat testing/traces-short/tr4 | testing/a.out config/All-FA.txt               > testing/output/tr4.All-FA &
wait
cat testing/traces-short/tr4 | testing/a.out config/Default.txt              > testing/output/tr4.default &
cat testing/traces-short/tr4 | testing/a.out config/L1-2way.txt              > testing/output/tr4.L1-2way &
cat testing/traces-short/tr4 | testing/a.out config/L1-8way.txt              > testing/output/tr4.L1-8way &
cat testing/traces-short/tr4 | testing/a.out config/L1-small-4way.txt        > testing/output/tr4.L1-small-4way &
wait
cat testing/traces-short/tr4 | testing/a.out config/L1-small.txt             > testing/output/tr4.L1-small &
cat testing/traces-short/tr4 | testing/a.out config/L2-4way.txt              > testing/output/tr4.L2-4way &
cat testing/traces-short/tr4 | testing/a.out config/L2-Big.txt               > testing/output/tr4.L2-Big &
wait

cat testing/traces-short/tr5 | testing/a.out config/All-2way.txt             > testing/output/tr5.Al3-2way &
cat testing/traces-short/tr5 | testing/a.out config/All-4way.txt             > testing/output/tr5.All-4way &
cat testing/traces-short/tr5 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr5.All-FA-L2Big &
cat testing/traces-short/tr5 | testing/a.out config/All-FA.txt               > testing/output/tr5.All-FA &
wait
cat testing/traces-short/tr5 | testing/a.out config/Default.txt              > testing/output/tr5.default &
cat testing/traces-short/tr5 | testing/a.out config/L1-2way.txt              > testing/output/tr5.L1-2way &
cat testing/traces-short/tr5 | testing/a.out config/L1-8way.txt              > testing/output/tr5.L1-8way &
cat testing/traces-short/tr5 | testing/a.out config/L1-small-4way.txt        > testing/output/tr5.L1-small-4way &
wait
cat testing/traces-short/tr5 | testing/a.out config/L1-small.txt             > testing/output/tr5.L1-small &
cat testing/traces-short/tr5 | testing/a.out config/L2-4way.txt              > testing/output/tr5.L2-4way &
cat testing/traces-short/tr5 | testing/a.out config/L2-Big.txt               > testing/output/tr5.L2-Big &
wait

cat testing/traces-short/tr6 | testing/a.out config/All-2way.txt             > testing/output/tr6.Al3-2way &
cat testing/traces-short/tr6 | testing/a.out config/All-4way.txt             > testing/output/tr6.All-4way &
cat testing/traces-short/tr6 | testing/a.out config/All-FA-L2Big.txt         > testing/output/tr6.All-FA-L2Big &
cat testing/traces-short/tr6 | testing/a.out config/All-FA.txt               > testing/output/tr6.All-FA &
wait
cat testing/traces-short/tr6 | testing/a.out config/Default.txt              > testing/output/tr6.default &
cat testing/traces-short/tr6 | testing/a.out config/L1-2way.txt              > testing/output/tr6.L1-2way &
cat testing/traces-short/tr6 | testing/a.out config/L1-8way.txt              > testing/output/tr6.L1-8way &
cat testing/traces-short/tr6 | testing/a.out config/L1-small-4way.txt        > testing/output/tr6.L1-small-4way &
wait
cat testing/traces-short/tr6 | testing/a.out config/L1-small.txt             > testing/output/tr6.L1-small &
cat testing/traces-short/tr6 | testing/a.out config/L2-4way.txt              > testing/output/tr6.L2-4way &
cat testing/traces-short/tr6 | testing/a.out config/L2-Big.txt               > testing/output/tr6.L2-Big &
wait

zcat testing/traces-1M/sjeng.gz | testing/a.out config/All-2way.txt             > testing/output/sjeng-1M.All-2way &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/All-4way.txt             > testing/output/sjeng-1M.All-4way &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/All-FA-L2Big.txt         > testing/output/sjeng-1M.All-FA-L2Big &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/All-FA.txt               > testing/output/sjeng-1M.All-FA &
wait
zcat testing/traces-1M/sjeng.gz | testing/a.out config/Default.txt              > testing/output/sjeng-1M.default &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L1-2way.txt              > testing/output/sjeng-1M.L1-2way &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L1-8way.txt              > testing/output/sjeng-1M.L1-8way &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L1-small-4way.txt        > testing/output/sjeng-1M.L1-small-4way &
wait
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L1-small.txt             > testing/output/sjeng-1M.L1-small &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L2-4way.txt              > testing/output/sjeng-1M.L2-4way &
zcat testing/traces-1M/sjeng.gz | testing/a.out config/L2-Big.txt               > testing/output/sjeng-1M.L2-Big &
