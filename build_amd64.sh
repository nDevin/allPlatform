#/bin/sh
rm -rf ./build
mkdir ./build
cd ./build
cmake -DBUILD_PLATFORM=amd64 ..
make -j4

export LD_LIBRARY_PATH="/home/SZ3864/Gitlab/test/allDemo/Amd64_bag/qt5.12.0-amd64/lib:$LD_LIBRARY_PATH"