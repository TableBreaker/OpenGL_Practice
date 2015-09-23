#!/usr/bin/env bash

file=$1

g++ ${file}.cpp -o bin/${file}.o -framework OpenGL -framework GLUT
chmod +x bin/${file}.o
./bin/${file}.o
