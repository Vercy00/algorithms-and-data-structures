#include <iostream>
#include <vector>
#include "helper/timer.h"
#include "helper/random.h"

struct area {
    int startNum;
    int endNum;
    int begin;
    int end;
};

void combSort(std::vector<area> &vec) {
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

        for (int i = 0; i < vec.size() - gap; i++)
            if (vec[i].startNum > vec[i + gap].startNum) {
                std::swap(vec[i], vec[i + gap]);
                swapped = true;
            }
    }
}

void combSort(std::vector<int> &vec) {
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

        for (int i = 0; i < vec.size() - gap; i++)
            if (vec[i] > vec[i + gap]) {
                std::swap(vec[i], vec[i + gap]);
                swapped = true;
            }
    }
}

std::vector<area> findSortedAreas(const std::vector<int> &vec) {
    std::vector<area> areas;
    area temp = {vec[0], 0, 0, 0};
    bool isBigger = false;

    for (int i = 0; i < vec.size() - 1; i++) {
        temp.end = i;

        if (vec[i] > vec[i + 1]) {
            temp.endNum = vec[i];

            areas.push_back(temp);

            temp = {vec[i + 1], 0, i + 1, i + 1};
            isBigger = false;
        } else if (!isBigger) {
            for (auto a: areas)
                if (a.endNum < vec[i + 1]) {
                    temp.endNum = vec[i];

                    areas.push_back(temp);

                    temp = {vec[i + 1], 0, i + 1, i + 1};
                    isBigger = true;
                }
        }
    }

    temp.end++;
    temp.endNum = vec[temp.end];
    areas.push_back(temp);

    return areas;
}

void sort(std::vector<int> &vec) {
    std::vector<area> areas = findSortedAreas(vec);
    std::vector<int> temp;

    combSort(areas);

    for (auto a: areas)
        temp.insert(temp.end(), vec.begin() + a.begin, vec.begin() + a.end);

    std::copy(temp.begin(), temp.end(), vec.begin());
}

int main() {
    int count = 10'000;
    int step = 100;

    std::vector<int> vec = {9, 10, 12, 15, 16, 1, 2, 4, 6, 8, 20, 25, 34, 37, 80};

//    for (int i = 0; i < count; i++)
//        vec.push_back(lib::randomInt(0, 100'000));
//
//    for (int i = 0; i < count - step; i += step)
//        combSort(vec, i, i + 100);

    lib::runWithTimer([&]() {
        sort(vec);
    }, "Custom sort");

    lib::runWithTimer([&]() {
        combSort(vec);
    }, "Comb sort");

//    for (auto a: vec)
//        std::cout << a << "\n";

    return 0;
}
