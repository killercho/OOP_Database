#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h"

class DoubleCell : public Cell {
private:
    double data;

public:
    DoubleCell(double data);
    virtual void read(std::istream& is) override;
    virtual void write(std::ostream& os) const override;

    virtual Cell* clone() const override;
};

#endif
