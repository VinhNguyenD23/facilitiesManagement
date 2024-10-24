#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include "../object/Facility.h"

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

public:
    AVLTree();
    ~AVLTree();
    int getHeight(Node *node);
    int getBalance(Node *node);
    Node *insert(Node *node, T data, K key);
    void preOrder(Node *node);
    void insert(T data, K key);
    Node *findIndex(K key);
    Node *deleteNode(Node *node, K key);
};

#endif // AVL_TREE_H
