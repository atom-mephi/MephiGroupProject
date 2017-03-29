#!/bin/bash

mkdir build -p
cd build

cxxtestgen --error-printer -o runner.cpp ../test_array.h ../test_print.h ../test_random_access_iterator.h
g++ -std=c++14 -o runner -I"../../../cxxtest-4.4" runner.cpp
./runner
