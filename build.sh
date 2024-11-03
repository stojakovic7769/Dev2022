#! /bin/bash

BuildTime="$(date +%Y-%m-%d\ %H:%M:%S)"
echo "Start Build at $BuildTime"

if [ -d "build" ]; then
    echo "build Directory existed!"
else
    echo "Creat Directory build!"
    mkdir build
fi

if [ -d "bin" ]; then
    echo "bin Directory existed!"
else
    echo "Creat Directory bin!"
    mkdir bin
fi

#uic -o ./Inc/ui_operatewindow.h ./Src/operatewindow.ui
#uic -o ./Inc/ui_mainwindow.h ./Src/mainwindow.ui


cd build
#注：cmake指令后面有一个参数，指的是CMakeLists.txt文件对于当前执行路径的相对路径，
#   本例程是在build文件夹下执行cmake指令，CMakeLists.txt文件在当前目录的上一级目录，所以参数为：..
cmake ../

make

cd ..

cd bin

./Test