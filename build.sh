#!/bin/bash
set -e -x

mkdir -p cmake
cd cmake
cmake ..
make
