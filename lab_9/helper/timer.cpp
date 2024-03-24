//
// Created by david on 21.11.2023.
//

#include <chrono>
#include <iostream>
#include "timer.h"

namespace lib {
    void runWithTimer(const std::function<void()> &fc, const std::string &name) {
        auto start = std::chrono::system_clock::now();

        fc();

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        std::cout << "\"" << name << "\" time elapsed " << elapsed << "ms\n";
    }
} // lib