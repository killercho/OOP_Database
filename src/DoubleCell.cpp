#include "../headers/DoubleCell.h"

DoubleCell::DoubleCell(double data)
{
    this->data = data;
}

void DoubleCell::readBinary(std::istream& is)
{
    is.read((char*)&data, sizeof(double));
}

void DoubleCell::writeBinary(std::ostream& os) const
{
    os.write((const char*)&data, sizeof(double));
}

void DoubleCell::write(std::ostream& os) const
{
    os << data;
}

Cell* DoubleCell::clone() const
{
    return new DoubleCell(*this);
}
