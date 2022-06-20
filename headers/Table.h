#ifndef TABLE_H
#define TABLE_H

#include "Cell.h"
#include "Column.h"
#include "String.h"
#include "Vector.h"

class Table {
private:
    Vector<Column> columns;
    String tableName;
    String fileName;

public:
    Table(const String& tableName, const String& fileName);

    const String& getTableName() const
    {
        return tableName;
    }
    const String& getFileName() const
    {
        return fileName;
    }

    void describeColumns() const;
    void printColumns() const;
    void changeName(const String& newName);

    void addRow(const String& data);                                     //!< Adds a cell to every column in the table. Where the data is in a String format and is getting parsed according to the needs of the column. The information is separated by a '\' symbol for each new column.
    void addColumn(const String& columnName, Cell::CellType columnType); //!< Adds a column at the end of the table.

    void saveTable() const;

    void writeBinary(std::ostream& os) const;
    void readBinary(std::istream& is, bool hasName = false);
    void write(std::ostream& os) const;
};

#endif
