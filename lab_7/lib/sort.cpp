//
// Created by david on 21.11.2023.
//

#include "sort.h"

namespace lib {
    unsigned long long Sort::bubbleSort(std::vector<int> &vec) {
        unsigned long long op = 0;
        bool swapped;

        for (int i = 0; i < vec.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < vec.size() - i - 1; j++)
                if (vec[j] > vec[j + 1]) {
                    std::swap(vec[j], vec[j + 1]);
                    swapped = true;

                    op++;
                }

            if (!swapped)
                break;
        }

        return op;
    }

    unsigned long long Sort::insertionSort(std::vector<int> &vec) {
        unsigned long long op = 0;

        for (int i = 1; i < vec.size(); i++) {
            int key = vec[i];
            int j = i - 1;

            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j = j - 1;
            }

            vec[j + 1] = key;
            op++;
        }

        return op;
    }

    unsigned long long Sort::selectionSort(std::vector<int> &vec) {
        unsigned long long op = 0;

        for (int i = 0; i < vec.size() - 1; i++) {
            int min = i;
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] < vec[min])
                    min = j;
            }

            if (min != i) {
                std::swap(vec[min], vec[i]);
                op++;
            }
        }

        return op;
    }

    unsigned long long Sort::combSort(std::vector<int> &vec) {
        unsigned long long op = 0;
        int gap = (int) vec.size();
        bool swapped = true;

        auto findGap = [](int gap) {
            gap = (gap * 10) / 13;

            if (gap < 1)
                return 1;

            return gap;
        };

        while (gap != 1 || swapped) {
            gap = findGap(gap);
            swapped = false;

            for (int i = 0; i < vec.size() - gap; i++) {
                if (vec[i] > vec[i + gap]) {
                    std::swap(vec[i], vec[i + gap]);
                    swapped = true;

                    op++;
                }
            }
        }

        return op;
    }

    unsigned long long Sort::shellSort(std::vector<int> &vec) {
        unsigned long long op = 0;

        for (int gap = (int) vec.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < vec.size(); i += 1) {
                int temp = vec[i];
                int j;

                for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                    vec[j] = vec[j - gap];
                    op++;
                }

                vec[j] = temp;
                op++;
            }
        }

        return op;
    }
} // lib