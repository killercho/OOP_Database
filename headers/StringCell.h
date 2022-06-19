#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"
#include "String.h"

class StringCell : public Cell {
private:
    String data;

public:
    StringCell(class String data);
    virtual void readBinary(std::istream& is) override;
    virtual void writeBinary(std::ostream& os) const override;
    virtual void write(std::ostream& os) const override;

    virtual Cell* clone() const override;
};

#endif
