#include <iostream>

class LinkedListNode {
public:
    int m_data {-1};
    LinkedListNode* m_next {nullptr};
};

class LinkedList {
private:
    LinkedListNode* m_start {nullptr};

public:
    LinkedList() : m_start(nullptr) {}

    void add(int num) {

    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    return output;
}

int main() {

    // test 1 - create a new linked list
    LinkedList list;

    // test 2 - add new elements to the list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 2 - adding nodes" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}