#/bin/sh
rm -rf ./build
mkdir ./build
cd ./build
cmake -DBUILD_PLATFORM=arm64 ..
make -j4
