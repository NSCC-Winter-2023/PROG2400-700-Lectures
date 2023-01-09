#ifndef _STUDENT_H
#define _STUDENT_H

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
    Student();
    Student(std::string name, std::string id);
    virtual ~Student() = default;

    // outputs student info in the format "Name: <name>, ID: <id>"
    void print_info();

    friend std::ostream& operator<<(std::ostream& output, Student& s);
};

#endif