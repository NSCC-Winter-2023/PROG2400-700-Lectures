#include <iostream>
#include <array>
#include <span>
#include <iomanip>
#include <queue>

std::ostream& operator<<(std::ostream& output, std::queue<int> queue) {
    while (!queue.empty()) {
        auto num = queue.front();
        queue.pop();
        output << std::setw(3) << num;
    }
    return output;
}

std::ostream& operator<<(std::ostream& output, std::span<int> array) {
    for (auto num : array) {
        output << std::setw(3) << num;
    }
    return output;
}

void split(std::queue<int>& merged, std::queue<int>& split1, std::queue<int>& split2) {

    int num_subfiles = 1;

    int prev = -1;
    while (!merged.empty()) {

        // read a record
        int curr = merged.front();
        merged.pop();

        // am i in another ordered list?
        if (curr < prev) num_subfiles++;

        // store record in files, odds/even pattern
        if (num_subfiles % 2 == 0) {
            split1.push(curr);
        } else {
            split2.push(curr);
        }

        prev = curr;
    }

}

bool elements_in_sublist(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() > last);
}

bool elements_in_file(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() > last) &&
            (second.empty() || (second.front() < last) || (first.front() < second.front()));
}

int merge(std::queue<int>& merged, std::queue<int>& split1, std::queue<int>& split2) {

    int num_subfiles = 0;

    // who starts the process?
    auto& first  = split2.empty() || (split1.front() < split2.front()) ? split1 : split2;
    auto& second = first == split1 ? split2 : split1;

    // merge while there are records to merge
    while (!split1.empty() || !split2.empty()) {

        int last = -1;

        // keep merging records while we are in an ordered list
        while (elements_in_sublist(first, second, last)) {
            // keep reading from a file while they are in order
            do {
                last = first.front();
                first.pop();
                merged.push(last);
            } while (elements_in_file(first, second, last));

            // switch over to other file and keep reading
            // if the other file has no records, stay in the first one
            if (!second.empty()) {
                std::swap(first, second);
            }
        }

        // move to next subfile
        num_subfiles++;
    }

    return num_subfiles;
}

void merge_sort(std::span<int> array) {
    int num_subfiles = 0;

    // copy array to merged queue
    std::queue<int> merged;
    for (auto num : array) {
        merged.push(num);
    }

    std::queue<int> split1, split2;
    do {
        split(merged, split1, split2);

        std::cout << "Split" << std::endl;
        std::cout << "split1: " << split1 << std::endl;
        std::cout << "split2: " << split2 << std::endl;

        num_subfiles = merge(merged, split1, split2);

        std::cout << "Merge" << std::endl;
        std::cout << merged << std::endl;

    } while (num_subfiles != 1);

    // copy merged queue to array
    int i = 0;
    while (!merged.empty()) {
        array[i++] = merged.front();
        merged.pop();
    }

}

int main() {

    auto nums = std::to_array({3, 6, 8, 10, 5, 9, 4, 1, 2, 7});

    std::cout << "Before Sorting..." << std::endl;
    std::cout << nums << std::endl;

    merge_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    std::cout << nums << std::endl;

    return 0;
}