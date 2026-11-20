#/bin/sh
rm -rf ./build
rm -rf ./demoAllPlatform
mkdir -p ./build
mkdir -p ./demoAllPlatform
cp ./run.sh ./demoAllPlatform/

cd ./build
cmake -DBUILD_PLATFORM=amd64 ..
make -j4

cp ./allPlatform ../demoAllPlatform/

cd ../demoAllPlatform
mkdir -p ./lib
