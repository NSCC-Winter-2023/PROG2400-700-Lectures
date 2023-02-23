#include <iostream>


int factorial(int num) {

    // the end of the recursion
    if (num == 1) {
        return 1;
    }

    return num * factorial(num - 1);
}

int main() {

    // a factorial is a mathematical expression
    // 5! = 5 x 4 x 3 x 2 x 1

    std::cout << "5! = " << factorial(5) << std::endl;

    return 0;
}