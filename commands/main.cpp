#include <iostream>
#include <sstream>

int main() {

    std::string input;
    std::cout << "Enter something: ";
    getline(std::cin, input);

    std::stringstream ss;
    ss << input;

    char command;
    int start, end;

    ss >> command >> start >> end;

    std::cout << "command: " << command;
    std::cout << ", start: " << start;
    std::cout << ", end: " << end << std::endl;

    if (!ss) {
        std::cout << "This is not a command!" << std::endl;
        std::cout << "Text: " << input << std::endl;
    } else {
        std::cout << "This IS a command!" << std::endl;
    }

    return 0;
}