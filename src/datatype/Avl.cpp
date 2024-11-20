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
void AVLTree<T, K>::clear(Node *node)
{
    if (node == nullptr)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::getroot()
{
    return this->root;
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
void AVLTree<T, K>::update(T data, K key)
{
    Node *element = this->find(root, key);
    if (element == nullptr)
    {
        throw DataException::DataNotFound("Data not found!");
    }
    element->data = data;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::findIndex(K key)
{
    return find(root, key);
}

template<class T, typename K>
void AVLTree<T, K>::remove(K key)
{
    this->root = this->remove(this->root, key);
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::remove(Node *node, K key)
{
    if (!find(node, key))
    {
        throw DataException::DataNotFound("Data not found!");
    }

    if (!node)
        return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else if(key == node->key)
    {
        if ((node->left == nullptr) || (node->right == nullptr))
        {
            Node *temp = node->left ? node->left : node->right;
            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
                *node = *temp;
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = remove(node->right, temp->key);
        }
    }

    if (!node)
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::getList()
{
    return this->root;
}

template <class T, typename K>
DArray<T> AVLTree<T, K>::toDynamicArray()
{
    DArray<T> data = DArray<T>();
    this->pushDataToDynamicArray(data, this->root);
    return data;
}

template <class T, typename K>
void AVLTree<T, K>::clear()
{
    clear(root);
    root = nullptr;
}

template <class T, typename K>
typename AVLTree<T, K>::Node *AVLTree<T, K>::find(Node *root, K key)
{
    if (root != nullptr)
    {
        if (root->key == key)
            return root;
        if (root->key < key && root->right != nullptr)
            return this->find(root->right, key);
        else if (root->key > key && root->left != nullptr)
            return this->find(root->left, key);
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
