#include "../headers/IntCell.h"

IntCell::IntCell(int data)
{
    this->data = data;
}

void IntCell::readBinary(std::istream& is)
{
    is.read((char*)&data, sizeof(int));
}

void IntCell::writeBinary(std::ostream& os) const
{
    os.write((const char*)&data, sizeof(int));
}

void IntCell::write(std::ostream& os) const
{
    os << data;
}

Cell* IntCell::clone() const
{
    return new IntCell(*this);
}
