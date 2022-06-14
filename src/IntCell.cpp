#include "../headers/IntCell.h"

IntCell::IntCell(int data)
{
    this->data = data;
}

void IntCell::read(std::istream& is)
{
    is >> data;
}

void IntCell::write(std::ostream& os) const
{
    os << data;
}

Cell* IntCell::clone() const
{
    return new IntCell(*this);
}
