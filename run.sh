#!/bin/sh

export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
chmod +x allPlatform
./allPlatform