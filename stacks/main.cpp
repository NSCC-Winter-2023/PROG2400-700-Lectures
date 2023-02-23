#include <iostream>

struct Student {
    std::string m_id;
    std::string m_name;
};

struct Node {
    Student m_data;
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_first {nullptr};
public:
    void push(Student student) {
        auto node = new Node();
        node->m_data = std::move(student);
        node->m_next = m_first;
        m_first = node;
    }

    void pop() {
        auto node = m_first;
        m_first = m_first ? m_first->m_next : nullptr;
        delete node;
    }

    Student peek() {
        return m_first ? m_first->m_data : Student({"W999999", "EMPTY"});
    }

    friend std::ostream& operator<<(std::ostream& output, Stack& stack) {
        auto node = stack.m_first;
        while (node != nullptr) {
            std::cout << "Name: " << node->m_data.m_name << ", ";
            std::cout << "ID: " << node->m_data.m_id << std::endl;
            node = node->m_next;
        }
        return output;
    }
};

int main() {

    // test 1 - add nodes to the stack
    Stack stack;

    stack.push({"W111222", "john"});
    stack.push({"W222333", "jill"});
    stack.push({"W333444", "jack"});
    stack.push({"W444555", "jane"});

    std::cout << stack << std::endl;

    // test 2 - remove nodes from the stack
    stack.pop();

    std::cout << stack << std::endl;

    return 0;
}