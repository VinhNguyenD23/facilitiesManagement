#include "Avl.h"

template <class T, typename K>
AVLTree<T, K>::AVLTree()
{
    this->root = nullptr;
}

template <class T, typename K>
AVLTree<T, K>::~AVLTree()
{
}

template <class T, typename K>
int AVLTree<T, K>::getHeight(Node *node)
{
    return node ? node->height : 0;
}

template <class T, typename K>
int AVLTree<T, K>::getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <class T, typename K>
void AVLTree<T, K>::pushDataToDynamicArray(DArray<T> &data, Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    this->pushDataToDynamicArray(data, node->left);
    data.push(node->data);
    this->pushDataToDynamicArray(data, node->right);
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::rightRotate(Node *y)
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
typename AVLTree<T, K>::Node *AVLTree<T, K>::leftRotate(Node *x)
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
typename AVLTree<T, K>::Node *AVLTree<T, K>::insert(Node *node, T data, K key)
{
    if (node == nullptr)
        return new Node(data, key);

    if (key < node->key)
        node->left = insert(node->left, data, key);
    else if (key > node->key)
        node->right = insert(node->right, data, key);
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
void AVLTree<T, K>::insert(T data, K key)
{
    this->root = insert(root, data, key);
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::findIndex(K key)
{
    return find(root, key);
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::deleteNode(Node *node, K key)
{
    // TODO: Delete Node in AVL Tree [ priority: normal ]
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;

    if (!find(node, key))
    {
        throw std::runtime_error("[ERROR] Element not found!");
    }
}

template <class T, typename K>
DArray<T> AVLTree<T, K>::toDynamicArray()
{
    DArray<T> data = DArray<T>();
    this->pushDataToDynamicArray(data, this->root);
    return data;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::find(Node *root, K key)
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
AVLTree<T, K>::Node::Node(T data, K key)
{
    this->key = key;
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

template class AVLTree<Facility, QString>;
