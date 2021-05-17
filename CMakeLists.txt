cmake_minimum_required(VERSION 3.17)
project(hardbrick)

set(CMAKE_CXX_STANDARD 17)

add_executable(hardbrick main.cpp Analysis/LexicalAnalysis/Scan.cpp Analysis/LexicalAnalysis/LexicalAnalysis.h Analysis/LexicalAnalysis/Lexer.cpp Analysis/LexicalAnalysis/LexerMain.cpp Analysis/SyntaxAnalysis/SyntaxAnalysis.h Analysis/SyntaxAnalysis/SyntaxMain.cpp)