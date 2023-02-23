#include <iostream>
#include <filesystem>
#include <queue>

namespace fs = std::filesystem;

void list_folders(const fs::path& path) {

    std::queue<std::pair<fs::path, int>> paths;

    for (const auto& entry: fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            paths.emplace(entry.path(), 0);
        }
    }

    while (!paths.empty()) {
        // pop one folder off the queue and go into that folder
        auto current = paths.front();
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

    return 0;
}