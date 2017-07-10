#!/bin/bash
set -e

mkdir -p cmake
cd cmake
cmake ..
make -j2
make test

echo
echo "--- Build Successful ---"""
echo
