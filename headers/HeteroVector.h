#ifndef HETEROVECTOR_H
#define HETEROVECTOR_H

#include <cstring>
#include <iostream>

/**
 * Template Vector class for heterogeneous container.
 * Main difference with the basic vector is that this container uses cloning of objects when copying.
 * */
template <typename T>
class HeteroVector {
private:
    T** arr;
    size_t capacity;
    size_t currentSize;

    static const short DEFAULT_STARTING_CAPACITY = 1;

    void copy(const T* const* arr, const size_t capacity, const size_t currentSize);
    void deleteMem();
    void resize();

public:
    HeteroVector();
    HeteroVector(const HeteroVector& other);
    HeteroVector<T>& operator=(const HeteroVector<T>& other);
    ~HeteroVector();

    void push(const T* element);
    void pop();

    size_t getSize() const;

    const T& operator[](size_t index) const; //!< Used to get a value in the array on a specific position in the array without the oprion of changing it.
    T& operator[](size_t index);             //!< Used to get a value in the array on a specific position with the option of changing that value.

    void writeBinary(std::ostream& os) const;
    void readBinary(std::istream& is);
    void write(std::ostream& os) const;
};

template <typename T>
void HeteroVector<T>::copy(const T* const* arr, size_t capacity, size_t currentSize)
{
    this->capacity = capacity;
    this->currentSize = currentSize;

    this->arr = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        this->arr[i] = arr[i]->clone();
    }
}

template <typename T>
void HeteroVector<T>::deleteMem()
{
    for (size_t i = 0; i < currentSize; ++i) {
        delete arr[i];
    }
    delete[] arr;
    currentSize = 0;
    capacity = 0;
}

template <typename T>
void HeteroVector<T>::resize()
{
    capacity *= 2;
    T** tmp = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        tmp[i] = arr[i]->clone();
        delete arr[i];
    }
    delete[] arr;
    arr = tmp;
    tmp = nullptr;
}

template <typename T>
HeteroVector<T>::HeteroVector()
{
    capacity = DEFAULT_STARTING_CAPACITY;
    currentSize = 0;
    arr = new T*[DEFAULT_STARTING_CAPACITY];
}

template <typename T>
HeteroVector<T>::HeteroVector(const HeteroVector<T>& other)
{
    copy(other.arr, other.capacity, other.currentSize);
}

template <typename T>
HeteroVector<T>& HeteroVector<T>::operator=(const HeteroVector<T>& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.arr, other.capacity, other.currentSize);
    }
    return *this;
}

template <typename T>
HeteroVector<T>::~HeteroVector()
{
    deleteMem();
}

template <typename T>
void HeteroVector<T>::push(const T* element)
{
    if (currentSize == capacity)
        resize();
    arr[currentSize++] = element->clone();
}

template <typename T>
void HeteroVector<T>::pop()
{
    currentSize--;
}

template <typename T>
size_t HeteroVector<T>::getSize() const
{
    return currentSize;
}

template <typename T>
const T& HeteroVector<T>::operator[](size_t index) const
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return *arr[index];
}

template <typename T>
T& HeteroVector<T>::operator[](size_t index)
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return *arr[index];
}

template <typename T>
void HeteroVector<T>::writeBinary(std::ostream& os) const
{
    os.write((const char*)&currentSize, sizeof(size_t));
    os.write((const char*)&capacity, sizeof(size_t));
    for (size_t i = 0; i < currentSize; ++i) {
        os.write((const char*)arr[i], sizeof(T));
    }
}

template <typename T>
void HeteroVector<T>::readBinary(std::istream& is)
{
    deleteMem();
    is.read((char*)&currentSize, sizeof(size_t));
    is.read((char*)&capacity, sizeof(size_t));
    arr = new T*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        is.read((char*)arr[i], sizeof(T));
    }
}

template <typename T>
void HeteroVector<T>::write(std::ostream& os) const
{
    os << "Count: " << currentSize;
    os << " Capacity: " << capacity;
    os << "Elements: ";
    for (size_t i = 0; i < currentSize; ++i) {
        os << *arr[i];
    }
}

#endif
