#include <iostream>
#include <string>
#include "student.h"

Student::Student() : Student(NAME, ID) {

}
Student::Student(std::string name, std::string id)
        : m_name(std::move(name)), m_id(std::move(id)) {

}

void Student::print_info() { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& output, Student& s) {
    output << "Name: " << s.m_name;
    output << ", ID: " << s.m_id;
    return output;
}
