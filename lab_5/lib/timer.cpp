#include <thread>
#include "timer.h"

namespace lib {
    void Timer::setInterval(const std::function<void()> &fc) {
        active = true;
        std::thread t([=]() {
            while (active.load()) {
                if (paused.load()) continue;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if (!active.load()) return;
                fc();
            }
        });
        t.detach();
    }

    void Timer::init(const std::function<void(int)> &fc) {
        setInterval([=]() {
            value++;
            fc(value.load());
        });
    }

    void Timer::stop() {
        paused = true;
    }

    void Timer::resume() {
        paused = false;
    }
} // lib