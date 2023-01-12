#include <iostream>

int main() {
    char str[] = "hello";
    char** ptr = (char **)str;
    int* iptr = (int *)str;
    std::cout << **ptr << std::endl;
    std::cout << *iptr << std::endl;
    std::cout << "Hello World" << std::endl;
    return 0;
}