#ifndef _DYNAMIC_ARRAY
#define _DYNAMIC_ARRAY

#include <iostream>
#include <initializer_list>

class DynamicArray {
private:
    int* m_nums{};
    int m_size{};
    int m_capacity{};

public:
    DynamicArray();
    DynamicArray(std::initializer_list<int> nums);

    void add(int num);
    int capacity() const;
    int size() const;

    friend std::ostream& operator<<(std::ostream& output, DynamicArray& d);
};

#endif