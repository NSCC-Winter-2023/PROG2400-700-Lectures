#include <iostream>
#include <cstring>

bool is_palindrome(char* input, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (input[i] != input[len-i-1]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome_recursive(char* input, int len) {

    // no word or a one letter word is a palindrome
    if (len <= 1) {
        return true;
    }

    // check first and last letters
    if (input[0] == input[len-1]) {
        // remove the two letters that are equal
        return is_palindrome_recursive(&input[1], len-2);
    }
    return false;
}

int main() {
    constexpr int BUFFER_SIZE = 80;
    char buffer[BUFFER_SIZE];

    std::cout << "Enter a word: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome(buffer, strlen(buffer))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " IS NOT a palindrome." << std::endl;
    }

    if (is_palindrome_recursive(buffer, strlen(buffer))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " IS NOT a palindrome." << std::endl;
    }
    return 0;
}