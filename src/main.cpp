#include "../headers/String.h"
#include <iostream>

#include "../headers/Cell.h"
#include "../headers/Column.h"
#include "../headers/StringCell.h"

int main()
{
    Column test(Cell::CellType::STRING, String("testing column"));
    test.addCell(String("cell1"));
    test.addCell(String("cell2"));

    Column test2(Cell::CellType::DOUBLE, String("testing double cell"));
    test2.addCell("13.4");
    test2.addCell("42.222");
    test2.addCell("-1.001");

    Column test3(Cell::CellType::INT, String("testing int cell"));
    test3.addCell("13");
    test3.addCell("-42.222");
    test3.addCell("-300");

    std::cout << test << '\n'
              << test2 << '\n'
              << test3;

    std::cout << "\nSuccess!";
}
