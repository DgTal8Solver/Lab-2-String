#include <iostream>

#include "str.h"

int main() {
    mt::MyString s1("Hello");
    mt::MyString s2(" World");
    s1[0] = 'W';
    s2[4] = 'k';
    std::cout << s1 + s2 << std::endl;

    return 0;
}