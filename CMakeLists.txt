cmake_minimum_required(VERSION 3.22)
project(PROG2400_700_Lectures)

set(CMAKE_CXX_STANDARD 23)

add_executable(echo echo/main.cpp)
add_executable(best_practices best_practices/main.cpp best_practices/student.cpp)