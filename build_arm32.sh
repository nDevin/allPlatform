#/bin/sh
rm -rf ./build
mkdir ./build
cd ./build
cmake -DBUILD_PLATFORM=arm32 ..
make -j4
