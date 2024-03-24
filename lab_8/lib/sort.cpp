//
// Created by david on 28.11.2023.
//

#include <algorithm>
#include "sort.h"

void Sort::bucketSort(std::vector<int> &vec) {
    int size = vec.size();
    std::vector<int> b[size];

    for (int i = 0; i < size; i++) {
        int bi = size * vec[i];
        b[bi].push_back(vec[i]);
    }

    for (int i = 0; i < size; i++)
        std::sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j : b[i])
            vec[index++] = j;
}
