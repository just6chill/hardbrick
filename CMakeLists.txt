cmake_minimum_required(VERSION 3.17)
project(first)

set(CMAKE_CXX_STANDARD 17)

add_executable(first main.cpp Parser/LexicalAnalysis/LexicalAnalysis.cpp Parser/LexicalAnalysis/LexicalAnalysis.h Global/Global.h)