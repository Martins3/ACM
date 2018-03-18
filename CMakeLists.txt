cmake_minimum_required(VERSION 3.8)
project(OnlineJudge)

set(CMAKE_CXX_STANDARD 11)



set(BUILD_2 memory)


#set(SOURCE_FILES_2 Main.cpp)
#set(SOURCE_FILES_2 poj/1/9/49.cpp)
set(SOURCE_FILES_2 uva/contest/12/UVa12661.cpp)
#set(SOURCE_FILES_2 uva/problems/1/UVa156.cpp)
#set(SOURCE_FILES_2 uva/lan.cpp)
#set(SOURCE_FILES_2 poj/3/2/others.cpp)


#set(SOURCE_FILES_2 wheels/SuffixArray.cpp)



add_executable(${BUILD_2} ${SOURCE_FILES_2})

