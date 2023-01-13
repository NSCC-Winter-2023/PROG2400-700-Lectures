#include "DynamicArray.h"

DynamicArray::DynamicArray() : m_nums(nullptr), m_size(0), m_capacity(0) {}
DynamicArray::DynamicArray(std::initializer_list<int> nums) : DynamicArray() {
    for (int num : nums) {
        add(num);
    }
}

std::ostream& operator<<(std::ostream& output, DynamicArray& d) {
    for (int i = 0; i < d.m_size; i++) {
        output << d.m_nums[i] << " ";
    }
    return output;
}

int DynamicArray::capacity() const { return m_capacity; }
int DynamicArray::size() const { return m_size; }

void DynamicArray::add(int num) {

    int *temp = nullptr;

    if (m_capacity == m_size) {
        // re-allocate to new capacity
        temp = m_nums;
        m_capacity += 5;
        m_nums = new int[m_capacity];

        // copy elements to new array
        for (int i = 0; i < m_size; i++) {
            m_nums[i] = temp[i];
        }
    }

    // add new element
    m_nums[m_size] = num;
    m_size++;

    // remove old array
    delete [] temp;
}