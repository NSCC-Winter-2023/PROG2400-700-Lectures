#include <iostream>
#include <cstring>

using std::cin, std::cout, std::endl;

int main() {

    const int BUFFER_SIZE = 80;
    const int ERROR_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    bool done = false;

    while (!done) {

        cout << "Enter some text: ";
        cin.getline(buffer, BUFFER_SIZE);

        if (!cin) {
            cin.clear();
            cin.ignore(ERROR_SIZE, '\n');
        }

        if (!strncmp(buffer, "end", BUFFER_SIZE - 1)) {
            done = true;
        } else {
            cout << "You typed: " << buffer << endl;
        }
    }

    return 0;
}