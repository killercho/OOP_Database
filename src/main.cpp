#include "../headers/String.h"
#include "../headers/Vector.h"
#include <iostream>

int main()
{
    Vector<int> intVector;
    intVector.push(4);
    intVector.push(2);
    intVector.pop();
    intVector.push(3);
    intVector.push(10);
    intVector.push(27);
    intVector.pop();

    std::cout << intVector.getSize() << '\n'
              << intVector[1] << '\n';
    std::cout << "Success!";
}
