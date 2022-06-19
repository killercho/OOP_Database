#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>
#include <iostream>

/**
 * Template Vector class.
 * */
template <typename T>
class Vector {
private:
    T** arr;
    size_t capacity;
    size_t currentSize;

    static const short DEFAULT_STARTING_CAPACITY = 1;

    void copy(const T** arr, const size_t capacity, const size_t currentSize);
    void deleteMem();
    void resize();

public:
    Vector();
    Vector(const Vector& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    void push(const T& element);
    void pop();

    size_t getSize() const;

    const T& operator[](size_t index) const; //!< Used to get a value in the array on a specific position in the array without the oprion of changing it.
    T& operator[](size_t index);             //!< Used to get a value in the array on a specific position with the option of changing that value.

    void writeBinary(std::ostream& os) const;
    void readBinary(std::istream& is);
    void write(std::ostream& os) const;
};

template <typename T>
void Vector<T>::copy(const T** arr, size_t capacity, size_t currentSize)
{
    this->capacity = capacity;
    this->currentSize = currentSize;

    this->arr = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        this->arr[i] = new T(*arr[i]);
    }
}

template <typename T>
void Vector<T>::deleteMem()
{
    for (size_t i = 0; i < capacity; ++i) {
        delete arr[i];
    }
    delete[] arr;
    currentSize = 0;
    capacity = 1;
}

template <typename T>
void Vector<T>::resize()
{
    capacity *= 2;
    T** tmp = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        tmp[i] = new T(*arr[i]);
        delete arr[i];
    }
    delete[] arr;
    arr = tmp;
    tmp = nullptr;
}

template <typename T>
Vector<T>::Vector()
{
    capacity = DEFAULT_STARTING_CAPACITY;
    currentSize = 0;
    arr = new T*[DEFAULT_STARTING_CAPACITY];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other.arr, other.capacity, other.currentSize);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.arr, other.capacity, other.currentSize);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    deleteMem();
}

template <typename T>
void Vector<T>::push(const T& element)
{
    if (currentSize == capacity)
        resize();
    arr[currentSize++] = new T(element);
}

template <typename T>
void Vector<T>::pop()
{
    currentSize--;
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return currentSize;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return *arr[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return *arr[index];
}

template <typename T>
void Vector<T>::writeBinary(std::ostream& os) const
{
    os.write((const char*)&currentSize, sizeof(size_t));
    os.write((const char*)&capacity, sizeof(size_t));
    for (size_t i = 0; i < currentSize; ++i) {
        os.write((char*)arr[i], sizeof(T));
    }
}

template <typename T>
void Vector<T>::readBinary(std::istream& is)
{
    deleteMem();
    is.read((char*)&currentSize, sizeof(size_t));
    is.read((char*)&capacity, sizeof(size_t));
    arr = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        arr[i]->readBinary(is);
    }
}

template <typename T>
void Vector<T>::write(std::ostream& os) const
{
    os << " Count: " << currentSize;
    os << " Capacity: " << capacity;
    os << " Elements: ";
    for (size_t i = 0; i < currentSize; ++i) {
        arr[i]->write(os); // Works only with the types that have defined 'write' function...
    }
}

#endif
