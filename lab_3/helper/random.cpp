//
// Created by david on 16.10.2023.
//

#include "random.h"

namespace app {

    int randomInt(int min, int max) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        static std::default_random_engine gen(seed);
        std::uniform_int_distribution<int> dist(min, max);

        return dist(gen);
    }

    unsigned int randomUInt(unsigned int min, unsigned int max) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        static std::default_random_engine gen(seed);
        std::uniform_int_distribution<unsigned int> dist(min, max);

        return dist(gen);
    }

} // app