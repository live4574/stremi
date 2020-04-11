#!/bin/bash
echo start environment setting

echo vim install...
sudo apt-get install vim

echo g++ install...
sudo apt install g++

echo making file..
sudo g++ -c life.cpp

g++ -o life life.o

./life

echo done