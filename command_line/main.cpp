#include <iostream>
#include <string>

using namespace std::string_literals;

int main(int argc, char* argv[]) {

    // do this!
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv: " << argv[i] << std::endl;
    }

    // don't do this!
    auto cmd{""s};
    std::cout << "Enter a command: ";
    std::cin >> cmd;

    return 0;
}