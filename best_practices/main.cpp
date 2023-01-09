#include <iostream>
#include "student.h"

int main() {

    // test 1 - create a new student
    Student student_one;
    std::cout << student_one << std::endl;

    // test 2 - member function
    student_one.print_info();

    // test 3 - two arg constructor
    Student student_two("John Smith", "W111111");
    student_two.print_info();

    return 0;
}