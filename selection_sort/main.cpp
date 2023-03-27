#include <iostream>
#include <array>
#include <span>
#include <iomanip>

void selection_sort(std::span<int> array) {

    for (auto i = 0; i < array.size() - 1; ++i) {
        // find the smallest number
        auto lowest = i;
        for (int j = i; j < array.size(); ++j) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }
        // swap with the current index if lower
        if (array[lowest] < array[i]) {
            std::swap(array[lowest], array[i]);
        }
    }
}

void dump_array(std::span<int> array) {
    for (auto num : array) {
        std::cout << std::setw(3) << num;
    }
    std::cout << std::endl;
}

int main() {

    auto nums = std::to_array({3, 6, 8, 10, 5, 9, 4, 1, 2, 7});

    std::cout << "Before Sorting..." << std::endl;
    dump_array(nums);

    selection_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    dump_array(nums);

    return 0;
}