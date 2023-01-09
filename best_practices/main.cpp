#include <iostream>
#include <string>

using namespace std::string_literals;

static const auto NAME{"default"s};
static const auto ID{"w123456"s};

// Purpose: a data class to contain regular student information.
// Author: Brian Shewan
// Date: 2023-Jan-09
class Student {
private:
    std::string m_name{NAME};   // fullname (firstname lastname)
    std::string m_id{ID};       // format: W9999999
public:
    Student() : Student(NAME, ID) {}
    Student(std::string name, std::string id)
        : m_name(std::move(name)), m_id(std::move(id)) {}
    virtual ~Student() = default;

    void print_info() { std::cout << *this << std::endl; }

    friend std::ostream& operator<<(std::ostream& output, Student& s);
};

std::ostream& operator<<(std::ostream& output, Student& s) {
    output << "Name: " << s.m_name;
    output << ", ID: " << s.m_id;
    return output;
}

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