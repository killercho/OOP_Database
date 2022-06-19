#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
public:
    virtual ~Cell() = default;

    virtual void readBinary(std::istream& is) = 0;
    virtual void writeBinary(std::ostream& os) const = 0;
    virtual void write(std::ostream& os) const = 0;

    virtual Cell* clone() const = 0;

    enum CellType {
        NULL_VALUE,
        INT,
        DOUBLE,
        STRING
    };
};

#endif
