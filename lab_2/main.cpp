#include <iostream>
#include "lib/list.h"
#include "lib/stack.h"
#include "helper/random.h"
#include "lib/tab_stack.h"
#include "lib/queue.h"

int main() {
    long m = 5;
    int l = 2;
    app::List<unsigned int> ints;
    app::Stack<unsigned int> stack;


    // *************** ZAD 1 ***************


    std::cout << "Zad 1\n";

    for (int i = 0; i < m; i++)
        ints.pushBack(app::randomUInt(0, UINT_MAX));

    std::cout << "\tCiag liczb:\n";
    for (auto obj: ints)
        std::cout << "\t\t" << obj << "\n";


    for (auto obj: ints)
        if (obj % l == 0)
            stack.push(obj);

    std::cout << "\n\tStos:\n";

    for (auto obj: stack)
        std::cout << "\t\t" << obj << "\n";


    // *************** ZAD 2 ***************


    std::cout << "\n\nZad 2\n\tStos:\n";

    for (auto obj: stack)
        std::cout << "\t\t" << obj << "\n";

    stack.reverseWithStack();

    std::cout << "\n\tStos po obrocie z stosem:\n";

    for (auto obj: stack)
        std::cout << "\t\t" << obj << "\n";

    stack.reverse();

    std::cout << "\n\tStos po obrocie:\n";

    for (auto obj: stack)
        std::cout << "\t\t" << obj << "\n";


    // *************** ZAD 3 ***************


    app::TabStack<unsigned int> tabStack;

    for (int i = 0; i < 10; i++)
        tabStack.push(app::randomUInt(0, UINT_MAX));

    std::cout << "\n\nZad 3\n\tStos:\n";

    for (int i = 0; i < tabStack.getSize(); ++i)
        std::cout << "\t\t" << tabStack[i] << "\n";

    int removeIndex = 1;
    tabStack.remove(removeIndex);

    std::cout << "\n\tStos po usunieciu index'u " << removeIndex << ".:\n";

    for (int i = 0; i < tabStack.getSize(); ++i)
        std::cout << "\t\t" << tabStack[i] << "\n";


    // *************** ZAD 4 ***************

    std::cout << "\n\nZad 4\n\tLista 1:\n";

    for (auto obj: ints)
        std::cout << "\t\t" << obj << "\n";

    app::List<unsigned int> ints2;

    for (int i = 0; i < 10; i++)
        ints2.pushBack(app::randomUInt(0, UINT_MAX));

    std::cout << "\n\tLista 2:\n";

    for (auto obj: ints2)
        std::cout << "\t\t" << obj << "\n";

    ints.shuffle(ints2);

    std::cout << "\n\tLista 1 po zlaczeniu:\n";

    for (auto obj: ints)
        std::cout << "\t\t" << obj << "\n";

    std::cout << "\n\tWielkosc Lista 2 po zlaczeniu:\n\t\t" << ints2.getSize() << "\n";


    // *************** ZAD 5 ***************


    std::cout << "\n\nZad 5\n\tKolejka:\n";

    app::Queue<unsigned int> queue;

    for (int i = 0; i < m; i++)
        queue.push(app::randomUInt(0, UINT_MAX));

    for (int i = 0; i < queue.getSize(); ++i)
        std::cout << "\t\t" << queue[i] << "\n";

    unsigned int objectToRemove = queue[1];
    queue.removeObj(objectToRemove);

    std::cout << "\n\tKolejka po usunieciu wartosci \"" << objectToRemove << "\":\n";

    for (int i = 0; i < queue.getSize(); ++i)
        std::cout << "\t\t" << queue[i] << "\n";

    return 0;
}
