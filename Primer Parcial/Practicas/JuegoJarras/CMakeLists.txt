cmake_minimum_required(VERSION 3.28)
project(JuegoJarras)

set(CMAKE_CXX_STANDARD 17)

add_executable(JuegoJarras main.cpp
        nodo.cpp
        nodo.h
        problemaJarras.cpp
        problemaJarras.h)
