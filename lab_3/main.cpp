#include <iostream>
#include "lib/list.h"
#include "helper/random.h"
#include "lib/stack.h"
#include "lib/queue.h"

#define CAP_VALUE 1000

struct pair {
    int fInt, sInt;

    pair(): fInt(0), sInt(0) {}
    pair(int fInt, int sInt): fInt(fInt), sInt(sInt) {}
};

void deleteMaxPair(app::Stack<pair> &stack);

int main() {
    app::List<pair> list;


    // *********** ZAD 1 ***********


    for (int i = 0; i < 10; i++)
        list.pushBack({app::randomInt(0, CAP_VALUE),
                       app::randomInt(0, CAP_VALUE)});

    std::cout << "Lista przed dodaniem sredniej:\n";
    for (auto p : list)
        std::cout << "\t" << p.fInt << "\t" << p.sInt << "\n";

    pair red = list.reducer<pair>([](pair &reduced, const pair &curr){
        reduced.fInt += curr.fInt;
        reduced.sInt += curr.sInt;

        return reduced;
    });

    red.fInt /= list.getSize();
    red.sInt /= list.getSize();

    list.pushBack(red);

    std::cout << "\n\n\n";
    std::cout << "Lista po dodaniu sredniej:\n";
    for (auto p : list)
        std::cout << "\t" << p.fInt << "\t" << p.sInt << "\n";


    // *********** ZAD 2 ***********


    app::Stack<pair> stack;

    for (auto p : list)
        stack.push(p);

    std::cout << "\n\n\n";
    std::cout << "Stos przed usuniecem max:\n";
    for (auto p : stack)
        std::cout << "\t" << p.fInt << "\t" << p.sInt << "\n";

    deleteMaxPair(stack);

    std::cout << "\n\n\n";
    std::cout << "Stos po usunieciu max:\n";
    for (auto p : stack)
        std::cout << "\t" << p.fInt << "\t" << p.sInt << "\n";


    // *********** ZAD 3 ***********


    app::Queue<pair> queue;

    for (auto p : stack)
        queue.push(p);

    std::cout << "\n\n\n";
    std::cout << "Kolejka przed posortowaniem:\n";
    for (auto p : queue)
        std::cout << "\t" << (p.fInt + p.sInt) << "\n";

    queue.sort([](const pair &curr, const pair &next){
        int currSum = curr.fInt + curr.sInt;
        int nextSum = next.fInt + next.sInt;

        if (currSum > nextSum)
            return 1;
        else if (currSum < nextSum)
            return -1;

        return 0;
    });

    std::cout << "\n\n\n";
    std::cout << "Kolejka po posortowaniu:\n";
    for (auto p : queue)
        std::cout << "\t" << (p.fInt + p.sInt) << "\n";

    return 0;
}

void deleteMaxPair(app::Stack<pair> &stack) {
    int largest = stack[0]->fInt;

    for (auto p : stack)
        if (p.fInt > largest)
            largest = p.fInt;
        else if (p.sInt > largest)
            largest = p.sInt;


    long idToRem = stack.find([&largest](const pair &obj){
        return obj.fInt == largest || obj.sInt == largest;
    });

    stack.remove(idToRem);
}
