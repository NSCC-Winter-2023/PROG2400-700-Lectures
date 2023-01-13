#include <iostream>
#include <vector>
#include <iomanip>
#include "DynamicArray.h"

std::ostream& operator<<(std::ostream& output, const std::vector<int>& v) {
    for (auto& n:v) {
        output << n << " ";
    }
    return output;
}

void operator<<(std::vector<int>& v, const std::vector<int>& in_vec) {
    for (auto& n:in_vec) {
        v.push_back(n);
    }
}

void array_demo() {
    // regular array
    char text[] = "abcdefghijklmnopqrstuvwxyz";
    std::cout << text << std::endl;

    // larger array
    auto large_text = new char[1024];
    for (int i = 0; i < 1024; ++i) {
        large_text[i] = (char)(i % 256);
    }
    large_text[1023] = '\0';
    std::cout << large_text << std::endl;
    std::cout << std::hex << (int)large_text[500] << std::endl;
    std::cout << std::hex << (int)*(large_text + 501) << std::endl;
}

void vector_demo() {

    // using vector
    std::vector<int> v {1, 2, 3, 4, 5};
    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v.push_back(6);

    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v << std::vector({7, 8, 9, 10, 11});

    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v << std::vector({12, 13, 14, 15, 16, 17, 18, 19, 20, 21});

    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v.shrink_to_fit();

    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v.reserve(25);

    std::cout << v << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
}

int main() {

    // test 1 - create a new dynamic array
    DynamicArray nums {1, 2, 3, 4, 5};
    std::cout << std::setw(10) << "size: " << nums.size() << " ";
    std::cout << std::setw(2) << "capacity: " << nums.capacity() << ") ";
    std::cout << nums << std::endl;

    // test 2 - add a new element
    nums.add(6);
    std::cout << std::setw(10) << "size: " << nums.size() << " ";
    std::cout << std::setw(2) << "capacity: " << nums.capacity() << ") ";
    std::cout << nums << std::endl;

    return 0;
}