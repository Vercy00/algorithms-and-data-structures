#include <iostream>
#include <vector>
#include "lib/BST.h"
#include "helper/range.h"
#include "lib/timer.h"

int main() {
    lib::Timer timer;
    lib::BST bst;

    bst.insert(41);
    bst.insert(47);
    bst.insert(50);
    bst.insert(58);

    std::vector<int> ints{48, 20, 54, 5};

    timer.setValue(0);
    timer.init([&](int time) {
        system("cls");

        std::cout << "Time: " << time << "\n\n";

        while (!ints.empty()) {
            int a = ints.back();

            if (a > time && !lib::checkInRange(bst, a, 3))
                bst.insert(a);
            else
                std::cout << "Cannot add flight " << a << " to flights";

            ints.pop_back();
        }

        std::cout << "\nFlights:\n";
        for (auto a: bst.inOrder())
            std::cout << a << "\n";

        for (auto i: bst.inOrder())
            if (time >= i)
                bst.deleteNode(i);

        std::cout << "\nEnter flight to add:\n";
    });
    timer.resume();

    while (true) {
        int fl;

        std::cin >> fl;

        ints.push_back(fl);
    }

    return 0;
}
