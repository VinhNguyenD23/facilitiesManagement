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
inline int AVLTree<T, K>::getHeight(Node *node)
{
    return node ? node->height : 0;
}

template <class T, typename K>
inline int AVLTree<T, K>::getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

template <class T, typename K>
AVLTree<T, K>::Node *AVLTree<T, K>::insert(Node *node, T data, K key)
{
    if (node == nullptr)
        return new Node(data, key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
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
    this->root = insert(root, data, key);
}

template <class T, typename K>
inline AVLTree<T, K>::Node *AVLTree<T, K>::findIndex(K key)
{
    return find(root, key);
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