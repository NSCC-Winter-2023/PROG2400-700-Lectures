#include <iostream>
#include <array>
#include <span>
#include <iomanip>

auto split(std::span<int> array) {
    // assume pivot is the first element
    auto pivot = array[0];

    // start searching for numbers greater and less than the pivot
    auto left = 0;
    auto right = array.size() - 1;

    // keep searching until all the elements are in the correct spots
    while (left < right) {
        // look on the left for numbers greater than the pivot
        while (pivot >= array[left]) {
            left++;
        }

        // look on the right for numbers less than the pivot
        while (pivot < array[right]) {
            right--;
        }

        // if found, swap them
        if (left < right) {
            std::swap(array[left], array[right]);
        }
    }

    // move pivot between left and right
    array[0] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(std::span<int> array) {

    if (array.size() <= 1) return;

    auto pivot = split(array);

    quick_sort(array.subspan(0, pivot));

    quick_sort(array.subspan(pivot + 1, array.size() - pivot - 1));
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

    quick_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    dump_array(nums);

    return 0;
}