#ifndef INTCELL_H
#define INTCELL_H

#include "Cell.h"

class IntCell : public Cell {
private:
    int data;

public:
    IntCell(int data);
    virtual void readBinary(std::istream& is) override;
    virtual void writeBinary(std::ostream& os) const override;
    virtual void write(std::ostream& os) const override;

    virtual Cell* clone() const override;
};

#endif
