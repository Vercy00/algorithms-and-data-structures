//
// Created by david on 14.11.2023.
//

#include "range.h"

namespace lib {
    bool checkInRange(BST bst, int key, int range) {
        for (int i = 0; i < range; i++)
            if (bst.exists(key + i + 1) || bst.exists(key - (i + 1)))
                return true;

        return false;
    }
} // lib