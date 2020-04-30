cmake_minimum_required(VERSION 3.15)
project(wet2)

set(CMAKE_CXX_STANDARD 14)

add_executable(wet2 main.cpp library1.h Artist.cpp Artist.h library1imp.cpp diesesystem.cpp diesesystem.h greatestHits.cpp greatestHits.h DSAVLTree.cpp DSAVLTree.h)