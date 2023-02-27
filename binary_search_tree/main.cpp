#include <iostream>
#include <iomanip>

struct Node;

using NodePtr = Node*;

struct Node {
    int m_data {-1};
    NodePtr m_left {nullptr};
    NodePtr m_right {nullptr};
};

class BST {
private:
    NodePtr m_root {nullptr};

public:
    void insert(int num) {
        insert(num, m_root);
    }

    friend std::ostream& operator<<(std::ostream& output, BST& bst) {
        bst.print(output, bst.m_root, 0);
        return output;
    }

private:
    void insert(int num, NodePtr& node) {
        if (node == nullptr) {
            node = new Node();
            node->m_data = num;
        } else {
            // add node to existing tree
            if (num < node->m_data) {
                // go left
                insert(num, node->m_left);
            } else if (num > node->m_data) {
                // go right
                insert(num, node->m_right);
            } else {
                // equal to
                std::cout << "duplicate value" << std::endl;
            }
        }
    }

    void print(std::ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            print(output, node->m_right, indent + 8);
            output << std::setw(indent) << node->m_data << std::endl;
            print(output, node->m_left, indent + 8);
        }
    }
};

int main() {

    // test 1 - add some nodes to the tree
    std::cout << std::endl;
    std::cout << "Test 1 - add some nodes" << std::endl;
    std::cout << "-----------------------" << std::endl;

    BST bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << bst << std::endl;

    return 0;
}