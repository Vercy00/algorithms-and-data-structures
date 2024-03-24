//
// Created by david on 23.10.2023.
//

#ifndef LAB_3_QUEUE_H
#define LAB_3_QUEUE_H

#include <initializer_list>
#include <functional>
#include "node.h"
#include "iterator.h"

namespace app {

    template<typename T>
    class Queue {
        node<T> *firstNode;
        long size;

        node<T> *getNode(long index) const {
            if (index < 0)
                index = size + index;

            if (index > size - 1 || index < 0)
                throw std::out_of_range("Out of range.");

            node<T> *tempNode = firstNode;
            if ((float) index < (float) size / 2)
                for (int i = 0; i != index; i++)
                    tempNode = tempNode->nextNode;
            else {
                index = size - index;

                for (int i = 0; i != index; i++)
                    tempNode = tempNode->prevNode;
            }

            return tempNode;
        }

        void push(long index, const T &obj) {
            if (index == size) {
                push(obj);
                return;
            }

            if (index > size - 1)
                throw std::out_of_range("Out of range.");

            auto currNode = getNode(index);
            auto n = new node<T>(currNode->prevNode, currNode, obj);

            currNode->prevNode->nextNode = n;
            currNode->prevNode = n;

            if (index == 0)
                firstNode = n;

            size++;
        }

    public:
        Iterator<T> begin() { return Iterator<T>(getNode(0), 0); }

        Iterator<T> end() { return Iterator<T>(firstNode->prevNode, size); }

        Queue() : size(0), firstNode(nullptr) {}

        Queue(std::initializer_list<T> arr) : size(0), firstNode(nullptr) {
            for (auto i = arr.begin(); i != arr.end(); i++)
                push(*i);
        }

        T *operator[](long index) const {
            return at(index);
        }

        T *at(long index) const {
            return &(getNode(index)->obj);
        }

        void push(const T &obj) {
            auto n = new node<T>(obj);

            if (firstNode == nullptr) {
                n->prevNode = n;
                firstNode = n;
            }

            node<T> *tempLastNode = firstNode->prevNode;

            n->prevNode = tempLastNode;
            n->nextNode = firstNode;
            tempLastNode->nextNode = n;
            firstNode->prevNode = n;

            size++;
        }

        T pop() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            T lastObj = firstNode->obj;
            remove(0);

            return lastObj;
        }

        [[nodiscard]] long getSize() const {
            return size;
        }

        void reverse() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            auto tempFirstNode = firstNode;
            auto currNode = tempFirstNode->prevNode;

            while (currNode != tempFirstNode) {
                auto tempNode = currNode->nextNode;
                currNode->nextNode = currNode->prevNode;
                currNode->prevNode = tempNode;

                currNode = currNode->nextNode;
            }

            firstNode = firstNode->prevNode;
        }

        void remove(long index) {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            auto node = getNode(index);
            auto newNext = node->nextNode;

            if (index == 0)
                firstNode = newNext;

            if (size == 1) {
                firstNode = nullptr;
            } else {
                node->nextNode->prevNode = node->prevNode;
                node->prevNode->nextNode = newNext;
            }

            delete node;

            size--;
        }

        long find(std::function<bool(const T &obj)> fc) {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            for (int i = 0; i < size; i++)
                if (fc(*at(i)))
                    return i;

            return -1;
        }

        void sort(std::function<int(const T &curr, const T &next)> fc) {
            int i = 0;

            while (i < size - 1) {
                T curr = *at(i);
                T next = *at(i + 1);

                if (fc(curr, next) == 1) {
                    remove(i);
                    remove(i);

                    push(i, curr);
                    push(i, next);

                    i = 0;
                    continue;
                }

                i++;
            }
        }
    };

} // app


#endif //LAB_3_QUEUE_H
