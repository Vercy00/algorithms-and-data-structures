//
// Created by david on 10.10.2023.
//

#ifndef AISD_LIST_H
#define AISD_LIST_H

#include <initializer_list>
#include <cmath>
#include <functional>
#include "node.h"
#include "iterator.h"

namespace app {
    template<typename T>
    class List {
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

    public:
        Iterator<T> begin() { return Iterator<T>(getNode(0), 0); }

        Iterator<T> end() { return Iterator<T>(firstNode->prevNode, size); }

        List() : size(0), firstNode(nullptr) {}

        List(std::initializer_list<T> arr) : size(0), firstNode(nullptr) {
            for (auto i = arr.begin(); i != arr.end(); i++)
                pushBack(*i);
        }

        T *operator[](long index) const {
            return at(index);
        }

        T *at(long index) const {
            return &(getNode(index)->obj);
        }

        void pushBack(const T &obj) {
            auto n = new node<T>(obj);

            if (size == 0) {
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

        void pushFront(const T &obj) {
            auto n = new node<T>(obj);

            if (firstNode == nullptr) {
                n->prevNode = n;
                firstNode = n;
            }

            n->nextNode = firstNode;
            n->prevNode = firstNode->prevNode;
            firstNode->prevNode = n;
            firstNode = n;

            size++;
        }

        [[nodiscard]] long getSize() const {
            return size;
        }

        long find(std::function<bool(const T &obj)> fc) {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            for (int i = 0; i < size; i++)
                if (fc(*at(i)))
                    return i;

            return -1;
        }

        List<T> filter(std::function<bool(const T &obj)> fc) {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            List<T> filteredList;

            for (int i = 0; i < size; i++)
                if (fc(*at(i)))
                    filteredList.pushBack(*at(i));

            return filteredList;
        }

        T popBack() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            auto lastNode = firstNode->prevNode;
            T lastObj = lastNode->obj;
            remove(size - 1);

            return lastObj;
        }

        T popFirst() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            T firstObj = firstNode->obj;
            remove(0);

            return firstObj;
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

        void removeObj(const T &obj) {
            for (int i = 0; i < size; i++)
                if (getNode(i)->obj == obj) {
                    remove(i);
                    return;
                }
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

        void clear() {
            while (size != 0)
                remove(0);
        }

        void shuffle(List<T> &list) {
            int listSize = list.getSize() > size ? size - 1 : list.getSize();
            for (int i = 0; i < listSize; i++)
                push((i * 2) + 1, list.popFirst());

            while (list.getSize() != 0)
                pushBack(list.popFirst());
        }

        template<typename R>
        R reducer(std::function<R(R &reduced, const T &curr)> fc) {
            R temp;

            for (int i = 0; i < size; i++)
                fc(temp, *at(i));

            return temp;
        }
    };
} // app

#endif //AISD_LIST_H
