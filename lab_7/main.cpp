#include <iostream>
#include <vector>
#include "helper/random.h"
#include "lib/sort.h"
#include "helper/timer.h"

int main() {
    std::vector<int> vec;

    for (int i = 0; i < 100'000; i++)
        vec.push_back(lib::randomInt(0, 1'000'000));

    std::vector<int> vec2;

    lib::runWithTimer([&](){
        vec2.assign(vec.begin(), vec.end());
        return lib::Sort::bubbleSort(vec2);
    }, "Bubble sort");

    lib::runWithTimer([&](){
        vec2.assign(vec.begin(), vec.end());
        return lib::Sort::insertionSort(vec2);
    }, "Insertion sort");

    lib::runWithTimer([&](){
        vec2.assign(vec.begin(), vec.end());
        return lib::Sort::selectionSort(vec2);
    }, "Selection sort");

    lib::runWithTimer([&](){
        vec2.assign(vec.begin(), vec.end());
        return lib::Sort::combSort(vec2);
    }, "Comb sort");

    lib::runWithTimer([&](){
        vec2.assign(vec.begin(), vec.end());
        return lib::Sort::shellSort(vec2);
    }, "Shell sort");

    return 0;
}
