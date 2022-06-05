#include "../headers/String.h"
#include <cstdlib>
#include <cstring>

void String::copy(const char* str)
{
    size = strlen(str);
    this->str = new char[size + 1];
    strcpy(this->str, str);
}

void String::deleteMem()
{
    delete[] str;
    size = 0;
}

String::String(const char* str)
{
    copy(str);
}

String::String(const String& other)
{
    copy(other.str);
}

String& String::operator=(const String& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.str);
    }
    return *this;
}

String::~String()
{
    deleteMem();
}

String::String(String&& other)
{
    str = other.str;
    size = strlen(str);

    other.str = nullptr;
    other.size = 0;
}

String& String::operator=(String&& other)
{
    if (this != &other) {
        deleteMem();

        str = other.str;
        size = strlen(str);

        other.str = nullptr;
        other.size = 0;
    }
    return *this;
}

bool String::operator==(const String& other) const
{
    return (strcmp(str, other.str) == 0);
}

String& String::operator+=(const String& other)
{
    size += other.size + 1;
    char* newStr = new char[size];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    str = newStr;
    return *this;
}

String operator+(const String& first, const String& second)
{
    String newString(first);
    newString += second;
    return newString;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
    // os.write((const char*)&other.size, sizeof(other.size));
    // os.write(other.str, other.size);

    os << other.str;
    return os;
}

std::istream& operator>>(std::istream& is, String& other)
{
    // other.deleteMem();
    // is.read((char*)&other.size, sizeof(other.size));
    // is.read(other.str, other.size);
    is >> other.str;
    other.size = strlen(other.str) + 1;
    return is;
}

size_t String::getSize() const
{
    return size;
}

const char* String::getStr() const
{
    return str;
}

bool isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

bool isSign(char c)
{
    return (c == '+' || c == '-');
}

bool isADot(char c)
{
    return (c == '.');
}

bool String::isIntNumber() const
{
    if (!isSign(str[0]) && !isNumber(str[0]))
        return false;

    for (size_t i = 1; i < size - 1; ++i) {
        if (!isNumber(str[i]))
            return false;
    }
    return true;
}

bool String::isDoubleNumber() const
{
    bool hasDot = false;
    if (!isSign(str[0]) && !isNumber(str[0]))
        return false;

    for (size_t i = 1; i < size - 1; ++i) {
        if (isADot(str[i])) {
            if (hasDot)
                return false;
            else
                hasDot = true;
        } else if (!isNumber(str[i]))
            return false;
    }
    return true;
}

int String::parseToInt() const
{
    if (!isIntNumber() && !isDoubleNumber())
        return 0;

    return atoi(str);
}

int pow(int number, int power)
{
    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= number;
    }
    return result;
}

double String::parseToDouble() const
{
    if (!isIntNumber() && !isDoubleNumber())
        return 0;

    bool hasSign = isSign(str[0]);
    int holePart = atoi(str);
    double doublePart = 0.0;
    int afterDotSymbols = 0;

    int dotIndex = 0;
    for (size_t i = 0; i < size; ++i) {
        if (isADot(str[i])) {
            dotIndex = i;
            break;
        }
    }
    if (dotIndex != 0) {
        afterDotSymbols = size - dotIndex - 2;
        doublePart = atoi(str + dotIndex + 1);
    }

    return holePart + (doublePart / pow(10, afterDotSymbols)) * (hasSign ? -1 : 1);
}
