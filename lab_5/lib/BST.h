//
// Created by david on 11.11.2023.
//

#ifndef AISD_LAB_3_BST_H
#define AISD_LAB_3_BST_H

#include <vector>

namespace lib {
    struct node {
        int key;
        node *right;
        node *left;
        node *parent;

        explicit node(int key) : key(key), right(nullptr), left(nullptr), parent(nullptr) {};
    };

    class BST {
        node *root;

        node *searchNode(int key);

        static int max(node *n);

        static int min(node *n);

    public:
        BST() : root(nullptr) {}

        bool exists(int key);

        void insert(int key);

        std::vector<int> inOrder();

        std::vector<int> preOrder();

        std::vector<int> postOrder();

        int max();

        int min();

        int height();

        int inOrderSuccessor(int key);

        int inOrderPredeccessor(int key);

        void deleteNode(int key);
    };

} // lib

#endif //AISD_LAB_3_BST_H
