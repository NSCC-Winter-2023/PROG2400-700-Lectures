#include <iostream>
#include <vector>

int main() {

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

    // using vector
    //td::vector<char>

    return 0;
}