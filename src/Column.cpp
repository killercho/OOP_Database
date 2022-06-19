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

void Column::writeBinary(std::ostream& os) const
{
    cells.writeBinary(os);
    os.write((const char*)&typeColumn, sizeof(typeColumn));
    name.writeBinary(os);
}

void Column::readBinary(std::istream& is)
{
    cells.readBinary(is);
    is.read((char*)&typeColumn, sizeof(typeColumn));
    name.readBinary(is);
}

void Column::write(std::ostream& os) const
{
    name.write(os);
    os << ": ";
    for (size_t i = 0; i < cells.getSize(); ++i) {
        cells[i].write(os);
        os << " ";
    }
}
