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
    String fileName("./testFiles/testing.bin");
    Vector<IntCell> test;
    std::ifstream file(fileName.getStr());
    if (file.is_open())
        std::cout << "The file is open for bussiness!\n";

    test.readBinary(file);
    std::cout << test.getSize();
    test.write(std::cout);

    std::cout << "\nSuccess!";
    file.close();
}
