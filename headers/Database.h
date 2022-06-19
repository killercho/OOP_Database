#ifndef DATABASE_H
#define DATABASE_H

#include "Cell.h"
#include "String.h"
#include "Table.h"
#include "Vector.h"

/**
 *  Database class to hold the information about all the tables in the database.
 */
class Database {
private:
    Vector<Table> tables;

public:
    bool import(const String& filename); //!< Adds a new table in the database. If the name of the new table exists then the function returns FALSE. Otherwise returns TRUE.
    // TODO:void showTables();                   //!< Prints a list of all the loaded tables.
    // TODO: void describe(const String& name); //!< Prints information about the types in a given table by it's name.
    // TODO: void print(const String& name); //!< Prints all the rows in a table.
    // TODO: void exportTable(const String& tableName, const String& filename); //!< Saves a given table in a file.
    // TODO:void select(size_t columnNumber, const String& value, const String& tableName); //!<Prints all the rows in the given table in the column with number 'columnNumber' that have 'value' as it's data.
    // TODO: void addColumn(const String& tableName, const String& columnName, Cell::CellType columnType); //!< Adds a column at the end. All the rows have NULL value.
    // TODO: void update(const String& tableName, size_t searchedColumnNumber, const String& searchedValue, );
    // TODO: void deleteRow(const String& tableName, size_t columnNumber, const String& value); //!< Deletes all the rows which have a cell with that value 'value'.
    // TODO: void insert(...);
    // TODO: void innerjoin(...);
    // TODO: void rename(...);
    // TODO: void count(...);
    // TODO: void aggregate(...);
};

#endif
