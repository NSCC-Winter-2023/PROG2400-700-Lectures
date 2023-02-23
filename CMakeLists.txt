cmake_minimum_required(VERSION 3.22)
project(PROG2400_700_Lectures)

set(CMAKE_CXX_STANDARD 23)

add_executable(echo echo/main.cpp)
add_executable(best_practices best_practices/main.cpp best_practices/student.cpp)
add_executable(command_line command_line/main.cpp)
add_executable(commands commands/main.cpp)
add_executable(dynamic_arrays dynamic_arrays/main.cpp dynamic_arrays/DynamicArray.cpp)
add_executable(linked_lists linked_lists/main.cpp)
add_executable(queues queues/main.cpp)
add_executable(smart_ptr smart_ptr/main.cpp)
add_executable(stacks stacks/main.cpp)