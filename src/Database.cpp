#include "../headers/Database.h"
#include <fstream>

void Database::saveTables() const
{
    for (size_t i = 0; i < tables.getSize(); ++i) {
        tables[i].saveTable();
    }
}

void Database::addColumn(const String& tableName, const String& columnName, Cell::CellType columnType)
{
    long index = tableIndex(tableName);
    if (index == -1)
        throw "Invalid name of the table.";
    tables[index].addColumn(columnName, columnType);
}

long Database::tableIndex(const String& tableName) const
{
    for (size_t i = 0; i < tables.getSize(); ++i) {
        if (tables[i].getTableName() == tableName) {
            return i;
        }
    }
    return -1;
}

void Database::rename(const String& oldName, const String& newName)
{
    long index = tableIndex(oldName);
    if (index == -1)
        throw "Table with that name does not exist.";
    tables[index].changeName(newName);
}

void Database::describe(const String& name) const
{
    long index = tableIndex(name);
    if (index != -1) {
        tables[index].describeColumns();
    } else
        throw "No such table with that name.";
}

bool Database::import(const String& filename)
{

    std::ifstream file(filename.getStr(), std::ios::binary);
    String newTableName;
    newTableName.readBinary(file);
    if (tableIndex(newTableName) == -1) {
        Table newTable(newTableName, filename);
        newTable.readBinary(file, true);
        tables.push(newTable);
    } else
        throw "A table with that name already exists";

    return false;
}

void Database::exportTable(const String& tableName, const String& filename) const
{
    long index = tableIndex(tableName);
    std::ofstream file(filename.getStr(), std::ios::binary);
    tables[index].writeBinary(file);
    file.close();
}

void Database::print(const String& name) const
{
    long index = tableIndex(name);
    if (index == -1)
        throw "No table with that name exists.";
    tables[index].printColumns();
}

void Database::showTables() const
{
    for (size_t i = 0; i < tables.getSize(); ++i) {
        tables[i].getTableName().write(std::cout);
        std::cout << ", ";
    }
    std::cout << '\n';
}
