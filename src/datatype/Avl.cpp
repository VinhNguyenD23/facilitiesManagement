#include "Avl.h"

template <class T, typename K>
inline AVLTree<T, K>::AVLTree()
{
    this->root = nullptr;
}

template <class T, typename K>
AVLTree<T, K>::~AVLTree()
{
}

template <class T, typename K>
inline int AVLTree<T, K>::height(Node *node)
{
    return node ? node->height : 0;
}

template <class T, typename K>
inline int AVLTree<T, K>::getBalance(Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::insert(Node *node, T data, K key)
{
    if (node == nullptr)
        return new Node(data, key);

    if (key < node->key)
        node->left = this->insert(node->left, key);
    else if (key > node->key)
        node->right = this->insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(this->height(node->left), this->height(node->right));

    int balance = this->getBalance(node);

    if (balance > 1 && key < node->left->key)
        return this->rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return this->leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = this->leftRotate(node->left);
        return this->rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = this->rightRotate(node->right);
        return this->leftRotate(node);
    }

    return node;
}

template <class T, typename K>
void AVLTree<T, K>::preOrder(Node *node)
{
    // TODO: Print AVL Tree [ priority: low ]
}

template <class T, typename K>
void AVLTree<T, K>::insert(T data, K key)
{
    this->root = this->insert(root, data, key);
}

template <class T, typename K>
inline AVLTree<T, K>::Node *AVLTree<T, K>::findIndex(K key)
{
    return this->find(root, key);
}

template <class T, typename K>
inline AVLTree<T, K>::Node *AVLTree<T, K>::deleteNode(Node *node, K key)
{
    // TODO: Delete Node in AVL Tree [ priority: normal ]
}

template <class T, typename K>
inline AVLTree<T, K>::Node *AVLTree<T, K>::find(Node *root, K key)
{
    // TODO: Find element in AVL Tree [ priority: normal ] [ In Testing ]
    if (root != nullptr)
    {
        if (root->key == key)
            return root;
        if (root->key < key)
            return this->find(root->left, key);
        else
            return this->find(root->right, key);
    }
    return nullptr;
}

template <class T, typename K>
inline AVLTree<T, K>::Node::Node(T data, K key)
{
    this->key = key;
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}