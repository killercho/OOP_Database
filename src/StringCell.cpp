#include "../headers/StringCell.h"

StringCell::StringCell(String data)
{
    this->data = data;
}

void StringCell::read(std::istream& is)
{
    is >> data;
}

void StringCell::write(std::ostream& os) const
{
    os << data;
}

Cell* StringCell::clone() const
{
    return new StringCell(*this);
}
