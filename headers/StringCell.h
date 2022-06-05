#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"
#include "String.h"

class StringCell : public Cell {
private:
    String data;

public:
    StringCell(String data);
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os) const;
};

#endif
