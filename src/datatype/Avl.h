#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../exception/DataException.h"
#include "../util/ValidateUtil.h"
#include <QDebug>

template <class T, typename K = int>
class AVLTree
{
public:
    class Node
    {
    public:
        K key;
        T data;
        Node *left;
        Node *right;
        int height;
        Node(T data, K key)
        {
            this->key = key;
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        }
    };

private:
    Node *root;

private:
    Node *find(Node *root, K key)
    {
        if (!ValidateUtil::isNull(root))
        {
            if (root->key == key)
                return root;
            if (root->key < key && !ValidateUtil::isNull(root->right))
                return this->find(root->right, key);
            else if (root->key > key && !ValidateUtil::isNull(root->left))
                return this->find(root->left, key);
        }
        return nullptr;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }
    Node *insert(Node *node, T data, K key)
    {
        if (ValidateUtil::isNull(node))
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
    Node *remove(Node *node, K key)
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
        else if (key == node->key)
        {
            if (ValidateUtil::isNull(node->left) || ValidateUtil::isNull(node->right))
            {
                Node *temp = node->left ? node->left : node->right;
                if (ValidateUtil::isNull(temp))
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
    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }
    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    void clear(Node *node)
    {
        if (ValidateUtil::isNull(node))
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (!ValidateUtil::isNull(current->left))
        {
            current = current->left;
        }
        return current;
    }

public:
    AVLTree()
    {
        this->root = nullptr;
    }
    ~AVLTree();
    void insert(T data, K key)
    {
        this->root = insert(root, data, key);
    }
    void update(T data, K key)
    {
        Node *element = this->find(root, key);
        if (ValidateUtil::isNull(element))
        {
            throw DataException::DataNotFound("Data not found!");
        }
        element->data = data;
    }
    Node *findIndex(K key)
    {
        return find(root, key);
    }
    void remove(K key)
    {
        this->root = this->remove(this->root, key);
    }
    Node *getList()
    {
        return this->root;
    }
    void clear()
    {
        clear(root);
        root = nullptr;
    }
};

#endif // AVL_TREE_H
