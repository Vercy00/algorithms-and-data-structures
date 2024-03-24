//
// Created by david on 16.10.2023.
//

#ifndef LAB_2_QUEUE_H
#define LAB_2_QUEUE_H

#include <initializer_list>
#include <stdexcept>

namespace app {

    template<typename T>
    class Queue {
        T *tab = new T[0];
        long size;

    public:
        Queue() : size(0), tab(nullptr) {}

        Queue(std::initializer_list<T> arr) : size(0), tab(nullptr) {
            for (auto i = arr.begin(); i != arr.end(); i++)
                push(*i);
        }

        T operator[](long index) const {
            return tab[index];
        }

        T at(long index) const {
            return tab[index];
        }

        void push(const T &obj) {
            T *newTab = new T[size + 1];

            if (size > 0)
                memcpy(newTab, tab, size * sizeof(T));

            newTab[size] = obj;
            tab = newTab;

            size++;
        }

        T pop() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            T firstObj = tab[0];

            T *newTab = new T[size - 1];
            memcpy(newTab, tab + 1, (size - 1) * sizeof(T));
            tab = newTab;

            size--;

            return firstObj;
        }

        [[nodiscard]] long getSize() const {
            return size;
        }

        void reverse() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            Queue queue;

            while (size != 0)
                queue.push(pop());

            *this = queue;
        }

        void remove(long index) {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            T *newTab = new T[size - 1];
            memcpy(newTab, tab, index * sizeof(T));
            memcpy(newTab + index, tab + index + 1, (size - index) * sizeof(T));
            tab = newTab;

            size--;
        }

        void removeObj(const T &obj) {
            for (int i = 0; i < size; i++)
                if (tab[i] == obj) {
                    remove(i);
                    return;
                }
        }
    };

} // app

#endif //LAB_2_QUEUE_H
