//
// Created by david on 16.10.2023.
//

#ifndef LAB_2_ITERATOR_H
#define LAB_2_ITERATOR_H

#include <iterator>
#include "node.h"

namespace app {
    template<typename T>
    struct Iterator : public std::iterator<std::forward_iterator_tag, T> {
        Iterator(node<T> *ptr, long size) : m_ptr(ptr), size(size) {}

        T &operator*() const {
            return m_ptr->obj;
        }

        T *operator->() {
            return &(m_ptr->obj);
        }

        Iterator &operator++() {
            m_ptr = m_ptr->nextNode;
            size++;
            return *this;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.m_ptr == b.m_ptr;
        };

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return a.size != b.size;
        };

    private:

        node <T> *m_ptr;
        long size;
    };
} // app

#endif //LAB_2_ITERATOR_H
