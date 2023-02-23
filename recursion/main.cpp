#include <iostream>

int count = 0;

void print() {
    count++;
    if (count < 510000) {
        print();
    }
}

int main() {
    std::cout << "Hello World" << std::endl;
    print();
    return 0;
}