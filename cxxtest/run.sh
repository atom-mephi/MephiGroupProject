#!/bin/bash

mkdir build -p
cd build

cxxtestgen --error-printer -o runner.cpp ../test_array.h
g++ -std=c++14 -o runner -I"../../../cxxtest-4.4" runner.cpp
./runner