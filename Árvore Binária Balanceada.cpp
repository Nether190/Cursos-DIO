#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

public:
    AVLTree() {
        root = nullptr;
    }

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        else {
            return node;  // Duplicate values are not allowed
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (value < node->left->value) {
                // Left-Left case
                return rotateRight(node);
            }
            else {
                // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balanceFactor < -1) {
            if (value > node->right->value) {
                // Right-Right case
                return rotateLeft(node);
            }
            else {
                // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printInOrderTraversal() {
        std::cout << "Caminhamento em ordem da árvore binária é: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.printInOrderTraversal();

    return 0;
}
