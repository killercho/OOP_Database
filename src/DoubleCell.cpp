#include "../headers/DoubleCell.h"

DoubleCell::DoubleCell(double data)
{
    this->data = data;
}

void DoubleCell::read(std::istream& is)
{
    is >> data;
}

void DoubleCell::write(std::ostream& os) const
{
    os << data;
}

Cell* DoubleCell::clone() const
{
    return new DoubleCell(*this);
}
