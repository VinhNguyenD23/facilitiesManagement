#include <iostream>
using namespace std;

// Node class to represent each node of the AVL Tree
class Node {
public:
    char MAVT[10];
    string TENVT;
    int DVT;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Get height of the node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Get balance factor of the node
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotate subtree rooted with y
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Insert a node into the AVL tree and balance it
    Node* insert(Node* node, int key) {
        // 1. Perform the normal BST insertion
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // Equal keys are not allowed in BST

        // 2. Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // 3. Get the balance factor of this node to check whether it became unbalanced
        int balance = getBalance(node);

        // If the node becomes unbalanced, there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Function to print pre-order traversal
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Function to insert key in the AVL Tree
    void insert(int key) {
        root = insert(root, key);
    }
};

int main() {
    AVLTree tree;

    cout << "Preorder traversal of the AVL tree is:\n";
    tree.preOrder(tree.root);

    return 0;
}
