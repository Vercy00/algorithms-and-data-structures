#ifndef AISD_LAB_3_TIMER_H
#define AISD_LAB_3_TIMER_H

#include <functional>
#include <atomic>

namespace lib {

    class Timer {
        std::atomic<bool> active{false}, paused{true};
        std::atomic<int> value{0};

        void setInterval(const std::function<void()> &fc);

    public:
        void init(const std::function<void(int)>& fc);

        void stop();

        void resume();

        void setValue(const int &startValue) {
            value = startValue;
        }

        [[nodiscard]] int getValue() const {
            return value;
        }
    };

} // lib

#endif //AISD_LAB_3_BST_H
