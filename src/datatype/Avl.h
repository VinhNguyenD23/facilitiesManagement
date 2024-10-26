#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include "../object/Facility.h"
#include "DynamicArray.h"
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
        Node(T data, K key);
    };

private:
    Node *root;

private:
    Node *find(Node *root, K key);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    Node *insert(Node *node, T data, K key);
    int getHeight(Node *node);
    int getBalance(Node *node);
    void pushDataToDynamicArray(DArray<T> &data, Node *node);

public:
    AVLTree();
    ~AVLTree();
    void insert(T data, K key);
    Node *findIndex(K key);
    Node *deleteNode(Node *node, K key);
    DArray<T> toDynamicArray();
};

#endif // AVL_TREE_H
