#include "../headers/Table.h"
#include <fstream>
#include <iostream>

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

void Table::printColumns() const
{
    for (size_t i = 0; i < columns.getSize(); ++i) {
        columns[i].write(std::cout);
    }
}

void Table::changeName(const String& newName)
{
    tableName = newName;
}

void Table::describeColumns() const
{
    for (size_t i = 0; i < columns.getSize(); ++i) {
        std::cout << columns[i].getColumnType() << ", ";
    }
    std::cout << '\n';
}

void Table::saveTable() const
{
    std::ofstream file(fileName.getStr(), std::ios::binary);
    if (!file.is_open())
        throw "File failed to open!";
    writeBinary(file);
    file.close();
}

void Table::writeBinary(std::ostream& os) const
{
    tableName.writeBinary(os);
    fileName.writeBinary(os);
    columns.writeBinary(os);
}

void Table::readBinary(std::istream& is, bool hasName)
{
    if (!hasName)
        tableName.readBinary(is);
    fileName.readBinary(is);
    columns.readBinary(is);
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
