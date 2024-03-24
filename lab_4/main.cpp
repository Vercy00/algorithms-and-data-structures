#include <iostream>
#include "lib/stack.h"

bool isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '{';
}

char getCloseBracket(char c) {
    switch (c) {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        default:
            return '0';
    }
}

bool checkIfBracketsValid(app::Stack<char> &stack) {
    app::Stack<char> temp;

    int openCount = 0;
    char closeBracket;
    for (auto c : stack)
        if (isOpenBracket(c)) {
            openCount++;
            closeBracket = getCloseBracket(c);
        } else if (c != closeBracket)
            temp.push(c);
        else if (c == closeBracket) {
            if (!checkIfBracketsValid(temp))
                return false;

            temp.clear();
            openCount--;
        }

    return openCount == 0;
}

bool checkIfBracketsClosed(app::Stack<char> &stack, const char brackets[2]) {
    int openCount = 0;
    for (auto c : stack)
        if (c == brackets[0])
            openCount++;
        else if (c == brackets[1])
            openCount--;

    return openCount == 0;
}

int main() {
    app::Stack<char> stack;
    std::string exp = "[(a + b) - {(b - c)] * [(d + e)}";

    for (auto c : exp)
        if (c != ' ')
            stack.push(c);

    std::cout << "Wszystkie nawiasy \"()\" " << (checkIfBracketsClosed(stack, "()") ? "" : "nie ") << "maja zamkniecia i otwarcia.\n";
    std::cout << "Wszystkie nawiasy \"[]\" " << (checkIfBracketsClosed(stack, "[]") ? "" : "nie ") << "maja zamkniecia i otwarcia.\n";
    std::cout << "Wszystkie nawiasy \"{}\" " << (checkIfBracketsClosed(stack, "{}") ? "" : "nie ") << "maja zamkniecia i otwarcia.\n";

    std::cout << "Kolejnosc jest " << (checkIfBracketsValid(stack) ? "" : "nie ") << "prawidlowa.\n";

    return 0;
}
