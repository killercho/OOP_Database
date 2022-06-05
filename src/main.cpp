#include "../headers/String.h"
#include <iostream>

int main()
{
    String test;
    std::cout << "Enter now: ";
    std::cin >> test;
    std::cout << test.parseToDouble() << " Success!";
}
