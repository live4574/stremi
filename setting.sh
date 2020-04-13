#!/bin/bash
echo start environment setting

echo vim install...
sudo apt-get install vim

echo g++ install...
sudo apt install g++

echo making file..
sudo g++ -c gameOfLife.cpp

g++ -o life gameOfLife.o

echo done