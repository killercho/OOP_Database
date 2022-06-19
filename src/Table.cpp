#include "../headers/Table.h"

Table::Table(const String& tableName, const String& filename)
    : tableName(tableName)
    , fileName(filename)
{
}

void Table::addColumn(const String& columnName, Cell::CellType columnType)
{
    columns.push(Column(columnType, columnName));
}

void Table::addRow(const String& data)
{
}

void Table::writeBinary(std::ostream& os) const
{
    columns.writeBinary(os);
    tableName.writeBinary(os);
    fileName.writeBinary(os);
}

void Table::readBinary(std::istream& is)
{
    columns.readBinary(is);
    tableName.readBinary(is);
    fileName.readBinary(is);
}

void Table::write(std::ostream& os) const
{
    os << "Columns: ";
    columns.write(os);
    os << " Table name: ";
    tableName.write(os);
    os << " File name: ";
    fileName.write(os);
}
