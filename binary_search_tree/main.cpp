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

    void remove(int num) {
        NodePtr node = m_root;
        NodePtr parent = nullptr;

        // search for the node to delete
        while (node != nullptr) {
            if (num < node->m_data) {
                // go left
                parent = node;
                node = node->m_left;
            } else if (num > node->m_data) {
                // go right
                parent = node;
                node = node->m_right;
            } else {
                // found the node
                break;
            }
        }

        // didn't find the node
        if (node == nullptr) return;

        // if a node has two children
        // use the right-most node in the left tree as successor
        if (node->m_right != nullptr && node->m_left != nullptr) {
            // start on the left subtree
            NodePtr successor = node->m_left;

            // go as far right as possible
            parent = node;
            while (successor->m_right != nullptr) {
                parent = successor;
                successor = successor->m_right;
            }

            // swap values with the successor
            node->m_data = successor->m_data;

            // the successor becomes the node to delete
            node = successor;
        }

        // assume there is a subtree on the left
        NodePtr subtree = node->m_left;

        // if no child on the left, assume the right
        if (subtree == nullptr) {
            subtree = node->m_right;
        }

        // delete node with no children
        if (parent == nullptr) {
            // deleting the root node
        } else if (node == parent->m_left) {
            // detach from parent's left side
            parent->m_left = subtree;
        } else if (node == parent->m_right) {
            // detach from parent's right side
            parent->m_right = subtree;
        }

        // delete the node
        delete node;
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

    // test 2 - delete a node with no children
    std::cout << std::endl;
    std::cout << "Test 2 - remove node with no children" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    bst.remove(2);

    std::cout << bst << std::endl;

    // test 3 - delete a node with one child
    std::cout << std::endl;
    std::cout << "Test 3 - remove node with one child" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    bst.remove(3);

    std::cout << bst << std::endl;

    // test 4 - delete a node with two children
    std::cout << std::endl;
    std::cout << "Test 4 - remove node with two children" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    bst.remove(7);

    std::cout << bst << std::endl;

    return 0;
}