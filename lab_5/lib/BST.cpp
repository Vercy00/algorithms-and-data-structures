//
// Created by david on 11.11.2023.
//

#include <functional>
#include "BST.h"

namespace lib {
    node *BST::searchNode(int key) {
        node *tmp = root;

        std::function<void(node *)> rec = [&](node *n) {
            if (n == nullptr || tmp != root) return;

            if (n->key == key) {
                tmp = n;
                return;
            }

            rec(n->left);
            rec(n->right);
        };

        rec(root);

        if (tmp->key != key)
            return nullptr;

        return tmp;
    }

    int BST::max(node *n) {
        node *tmp = n;

        while (tmp->right != nullptr)
            tmp = tmp->right;

        return tmp->key;
    }

    int BST::min(node *n) {
        node *tmp = n;

        while (tmp->left != nullptr)
            tmp = tmp->left;

        return tmp->key;
    }

    void BST::insert(int key) {
        node **tmp = &root;
        node *parent = nullptr;

        while (true) {
            if (*tmp == nullptr) {
                *tmp = new node(key);
                (*tmp)->parent = parent;

                return;
            } else if ((*tmp)->key < key) {
                parent = *tmp;
                tmp = &((*tmp)->right);
            } else {
                parent = *tmp;
                tmp = &((*tmp)->left);
            }
        }
    }

    std::vector<int> BST::inOrder() {
        std::vector<int> res;

        std::function<void(node *)> rec = [&](node *n) {
            if (n == nullptr) return;

            rec(n->left);

            res.push_back(n->key);

            rec(n->right);
        };

        rec(root);

        return res;
    }

    std::vector<int> BST::preOrder() {
        std::vector<int> res;

        std::function<void(node *)> rec = [&](node *n) {
            if (n == nullptr) return;

            res.push_back(n->key);

            rec(n->left);
            rec(n->right);
        };

        rec(root);

        return res;
    }

    std::vector<int> BST::postOrder() {
        std::vector<int> res;

        std::function<void(node *)> rec = [&](node *n) {
            if (n == nullptr) return;

            rec(n->left);
            rec(n->right);

            res.push_back(n->key);
        };

        rec(root);

        return res;
    }

    int BST::max() {
        return max(root);
    }

    int BST::min() {
        return max(root);
    }

    int BST::height() {
        std::vector<int> res;

        std::function<int(node *)> rec = [&](node *n) {
            if (n == nullptr) return 0;

            return std::max(rec(n->left), rec(n->right)) + 1;
        };

        return rec(root);
    }

    int BST::inOrderSuccessor(int key) {
        node *tmp = searchNode(key);

        if (tmp->right != nullptr)
            return min(tmp->right);

        node *res = tmp->parent;
        while (res != nullptr && tmp == res->right) {
            tmp = res;
            res = res->parent;
        }

        return res->key;
    }

    int BST::inOrderPredeccessor(int key) {
        node *tmp = searchNode(key);

        if (tmp->left != nullptr)
            return max(tmp->left);

        node *res = tmp->parent;
        while (res != nullptr && tmp == res->left) {
            tmp = res;
            res = res->parent;
        }

        return res->key;
    }

    void BST::deleteNode(int key) {
        node *n = searchNode(key);

        if (n->left == nullptr && n->right == nullptr) {
            node *tmp = n->parent;

            if (tmp == nullptr)
                delete n;
            else if (tmp->left == n) {
                tmp->left = nullptr;

                delete n;
            } else {
                tmp->right = nullptr;

                delete n;
            }

        } else if (n->left == nullptr) {
            node *tmp = n->right;
            n->key = n->right->key;
            n->left = n->right->left;
            n->right = n->right->right;

            delete tmp;

            n->right = nullptr;
        } else if (n->right == nullptr) {
            node *tmp = n->left;
            n->key = n->left->key;
            n->right = n->left->right;
            n->left = n->left->left;

            delete tmp;

            n->left = nullptr;
        }
        else {
            node *suc = n->right;

            while (suc->left != nullptr)
                suc = suc->left;

            if (suc->parent != n)
                suc->parent->left = suc->right;
            else
                suc->parent->right = suc->right;

            n->key = suc->key;

            delete suc;
        }
    }

    bool BST::exists(int key) {
        return searchNode(key) != nullptr;
    }
} // lib