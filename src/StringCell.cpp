#include "../headers/StringCell.h"

StringCell::StringCell(String data)
{
    this->data = data;
}

void StringCell::readBinary(std::istream& is)
{
    data.readBinary(is);
}

void StringCell::writeBinary(std::ostream& os) const
{
    data.writeBinary(os);
}

void StringCell::write(std::ostream& os) const
{
    data.write(os);
}

Cell* StringCell::clone() const
{
    return new StringCell(*this);
}
