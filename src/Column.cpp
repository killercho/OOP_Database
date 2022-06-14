#include "../headers/Column.h"
#include "../headers/DoubleCell.h"
#include "../headers/IntCell.h"
#include "../headers/StringCell.h"

void Column::addCell(Cell::CellType type, String data)
{
    switch (type) {
    case Cell::CellType::INT: {
        cells.push(new IntCell(data.parseToInt()));
        break;
    }
    case Cell::CellType::DOUBLE: {
        cells.push(new DoubleCell(data.parseToDouble()));
        break;
    }
    case Cell::CellType::STRING: {
        cells.push(new StringCell(data));
        break;
    }
    default:
        break;
    }
}
