#!/bin/bash

#needed for g++ compilier on Janus
module load gcc

g++ -Wall -static -O3 --std=c++11 main.cpp processor.cpp l1cache.cpp l2cache.cpp memory.cpp way.cpp watcher.cpp

mv a.out testing/


