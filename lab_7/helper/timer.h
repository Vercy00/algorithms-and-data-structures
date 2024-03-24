//
// Created by david on 21.11.2023.
//

#ifndef LAB_7_TIMER_H
#define LAB_7_TIMER_H

#include <functional>

namespace lib {

    void runWithTimer(const std::function<unsigned long long()> &fc, const std::string &name);

} // lib

#endif //LAB_7_TIMER_H
