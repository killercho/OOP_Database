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
    long tableIndex(const String& tableName) const;
    void saveTables() const;

    bool import(const String& filename);                                     //!< Adds a new table in the database. If the name of the new table exists then the function returns FALSE. Otherwise returns TRUE.
    void showTables() const;                                                 //!< Prints a list of all the loaded tables.
    void describe(const String& name) const;                                 //!< Prints information about the types in a given table by it's name.
    void print(const String& name) const;                                    //!< Prints all the columns in a table.
    void exportTable(const String& tableName, const String& filename) const; //!< Saves a given table in a file.
    // TODO:void select(size_t columnNumber, const String& value, const String& tableName); //!<Prints all the rows in the given table in the column with number 'columnNumber' that have 'value' as it's data.
    void addColumn(const String& tableName, const String& columnName, Cell::CellType columnType); //!< Adds a column at the end.
    // TODO: void update(const String& tableName, size_t searchedColumnNumber, const String& searchedValue, );
    // TODO: void deleteRow(const String& tableName, size_t columnNumber, const String& value); //!< Deletes all the rows which have a cell with that value 'value'.
    // TODO: void insert(...);
    // TODO: void innerjoin(...);
    void rename(const String& oldName, const String& newName);
    // TODO: void count(...);
    // TODO: void aggregate(...);
};

#endif
