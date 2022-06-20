#include "../headers/String.h"
#include <fstream>
#include <iostream>

#include "../headers/Cell.h"
#include "../headers/Column.h"
#include "../headers/DoubleCell.h"
#include "../headers/IntCell.h"
#include "../headers/StringCell.h"
#include "../headers/Table.h"
#include "../headers/Vector.h"

int main()
{
    String someString("abc bum.opa filename!");

    Vector<String> separatedStrings = someString.splitStringBy(' ');

    for (size_t i = 0; i < separatedStrings.getSize(); ++i) {
        std::cout << separatedStrings[i].getStr();
    }

    std::cout << "\nSuccess!";
}
