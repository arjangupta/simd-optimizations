#!/bin/sh

rm -rf build/osx/
cmake -H. -Bbuild/osx/ -DCMAKE_BUILD_TYPE=Release
cd build/osx/
make -j 4