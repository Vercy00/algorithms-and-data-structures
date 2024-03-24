//
// Created by david on 16.10.2023.
//

#ifndef LAB_2_TAB_STACK_H
#define LAB_2_TAB_STACK_H

#include <initializer_list>
#include <stdexcept>

namespace app {

    template<typename T>
    class TabStack {
        T *tab = new T[0];
        long size;

    public:
        TabStack() : size(0), tab(nullptr) {}

        TabStack(std::initializer_list<T> arr) : size(0), tab(nullptr) {
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

            T lastObj = tab[size - 1];

            T *newTab = new T[size - 1];
            memcpy(newTab, tab, (size - 1) * sizeof(T));
            tab = newTab;

            size--;

            return lastObj;
        }

        [[nodiscard]] long getSize() const {
            return size;
        }

        void reverse() {
            if (size == 0)
                throw std::out_of_range("Size of list is 0.");

            TabStack tabStack;

            while (size != 0)
                tabStack.push(pop());

            *this = tabStack;
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

#endif //LAB_2_TAB_STACK_H
