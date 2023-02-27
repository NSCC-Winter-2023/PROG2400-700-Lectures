#include <iostream>
#include <filesystem>
#include <stack>

namespace fs = std::filesystem;

void list_folders_recursive(const fs::path& path, int indent=0) {
    for (const auto& entry: fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            std::cout << std::string(indent, ' ') << entry << std::endl;
            list_folders_recursive(entry, indent + 2);
        }
    }
}

void list_folders(const fs::path& path) {

    std::stack<std::pair<fs::path, int>> paths;

    for (const auto& entry: fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            paths.emplace(entry.path(), 0);
        }
    }

    while (!paths.empty()) {
        // pop one folder off the queue and go into that folder
        auto current = paths.top();
        std::cout << std::string(current.second, ' ') << current.first << std::endl;
        paths.pop();

        for (const auto& entry: fs::directory_iterator(current.first)) {
            if (entry.is_directory()) {
                paths.emplace(entry.path(), current.second + 2);
            }
        }
    }

}

int main() {

    auto path = fs::path(".");

    std::cout << std::endl;
    std::cout << "Non-recursive..." << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << std::endl;

    list_folders(path);

    std::cout << std::endl;
    std::cout << "Recursive..." << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << std::endl;

    list_folders_recursive(path);

    return 0;
}