#ifndef COLUMN_H
#define COLUMN_H

#include "Cell.h"
#include "HeteroVector.h"
#include "String.h"

class Column {
private:
    HeteroVector<Cell> cells;
    Cell::CellType typeColumn; //!< Used to identify the type of cells in the column: 0 is NULL, 1 is INT, 2 is DOUBLE, 3 is STRING.
    String name;

public:
    Column(Cell::CellType type, const String& name);
    void addCell(const String& data);

    const String& getName() const;
    const Cell& getCellAt(size_t index) const;

    void writeBinary(std::ostream& os) const;
    void readBinary(std::istream& is);
    void write(std::ostream& os) const;
};

#endif
