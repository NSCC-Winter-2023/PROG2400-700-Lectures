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
    virtual ~LinkedList() {
        auto node = m_start;
        while (node != nullptr) {
            auto temp = node;
            node = node->m_next;
            delete temp;
        }
    }

    void add(int num) {
        // create a new node
        auto new_node = new LinkedListNode();
        new_node->m_data = num;

        if (m_start == nullptr) {
            // attach it to the start of the linked list
            m_start = new_node;
        } else {
            // attach it the end of an existing chain
            auto node = m_start;
            LinkedListNode* prev = nullptr;

            // find the last node
            while (node != nullptr) {
                prev = node;
                node = node->m_next;
            }

            // attach new node to the node at the end of the chain
            prev->m_next = new_node;
        }
    }

    void insert(int num, int position) {

        // create a new node
        auto new_node = new LinkedListNode();
        new_node->m_data = num;

        // locate node to insert before
        auto node = m_start;
        LinkedListNode* prev = nullptr;

        int curr_pos = 1;
        while (node != nullptr) {
            if (curr_pos++ == position) {
                break;
            }
            prev = node;
            node = node->m_next;
        }

        // is this the first node?
        if (prev == nullptr) {
            // first node
            new_node->m_next = m_start;
            m_start = new_node;
        } else {
            // other node
            new_node->m_next = prev->m_next;
            prev->m_next = new_node;
        }
    }

    void remove(int num) {
        // find the last node in the chain
        auto node = m_start;
        LinkedListNode* prev = nullptr;

        while (node != nullptr) {
            // find the node with the right data
            if (node->m_data == num) {
                break;
            }
            prev = node;
            node = node->m_next;
        }

        // did we find the node we want to delete?
        if (node != nullptr) {
            // determine first or other node
            if (prev == nullptr) {
                // deleting the first node
                m_start = node->m_next;
            } else {
                // a different node in the chain
                prev->m_next = node->m_next;
            }

            delete node;
        }
    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list.m_start;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
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

    // test 3 - delete the node at the end of the chain
    list.remove(5);

    std::cout << "Test 3 - delete last node" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 4 - delete the node at the beginning of the chain
    list.remove(1);

    std::cout << "Test 4 - delete first node" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 5 - delete the node in the middle of the chain
    list.remove(3);

    std::cout << "Test 5 - delete middle node" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 6 - insert a node at the beginning of the chain
    list.insert(100, 1); // insert 100 before line 1

    std::cout << "Test 6 - insert first node" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 7 - insert a node in the middle of the chain
    list.insert(200, 3); // insert 200 before line 3

    std::cout << "Test 7 - insert middle node" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}