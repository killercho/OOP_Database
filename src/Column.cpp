#include "../headers/Column.h"
#include "../headers/DoubleCell.h"
#include "../headers/IntCell.h"
#include "../headers/StringCell.h"

Column::Column(Cell::CellType type, const String& name)
{
    this->name = name;
    typeColumn = type;
}

void Column::addCell(const String& data)
{
    switch (typeColumn) {
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

const String& Column::getName() const
{
    return name;
}

const Cell& Column::getCellAt(size_t index) const
{
    return cells[index];
}

std::ostream& operator<<(std::ostream& os, const Column& other)
{
    os << other.name << ": ";
    for (size_t i = 0; i < other.cells.getSize(); ++i) {
        other.cells[i].write(os);
        os << " ";
    }

    return os;
}
std::istream& operator>>(std::istream& is, Column& other)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    other.name = String(buffer);
    size_t cellsSize = 0;
    is >> cellsSize;
    for (size_t i = 0; i < cellsSize; ++i) {
        other.cells[i].read(is);
    }

    return is;
}
