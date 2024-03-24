//
// Created by david on 21.11.2023.
//

#ifndef LAB_7_SORT_H
#define LAB_7_SORT_H

#include <vector>

namespace lib {

    class Sort {
    public:
        static unsigned long long bubbleSort(std::vector<int> &vec);

        static unsigned long long insertionSort(std::vector<int> &vec);

        static unsigned long long selectionSort(std::vector<int> &vec);

        static unsigned long long combSort(std::vector<int> &vec);

        static unsigned long long shellSort(std::vector<int> &vec);
    };

} // lib

#endif //LAB_7_SORT_H
