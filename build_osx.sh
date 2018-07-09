#!/bin/sh

rm -rf build/osx/
cmake -H. -Bbuild/osx/ -DOSX=True -DCMAKE_BUILD_TYPE=Release
cd build/osx/
make -j 4