#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:
    T *pItems;
    size_t len;
    size_t cap;

public:
    Array(int capacity);
    ~Array();

public:
    void append(T item);
    void removeAt(int index);
    int indexOf(T item);
    void print();
};

template <typename T>
Array<T>::Array(int capacity)
{
    pItems = new T[capacity];
    memset(pItems, 0, sizeof(T) * capacity);
    len = 0;
    cap = capacity;
}

template <typename T>
Array<T>::~Array()
{
    len = cap = 0;
    delete[] pItems;
}

template <typename T>
void Array<T>::append(T item)
{
    if (len == cap)
    {
        cap = cap * 2;
        T *pTemp = new T[cap];
        memcpy(pTemp, pItems, sizeof(T) * len);
        if (pItems)
            delete[] pItems;
        pItems = pTemp;
    }
    pItems[len++] = item;
}

template <typename T>
void Array<T>::removeAt(int index)
{
    if (index < 0 || index >= len)
        throw std::out_of_range("invalid index!");
    for (int i = index; i < len - 1; i++)
        pItems[i] = pItems[i + 1];
    len--;
}

template <typename T>
int Array<T>::indexOf(T item)
{
    for (int i = 0; i < len; i++)
        if (pItems[i] == item)
            return i;
    return -1;
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < len; i++)
        cout << pItems[i] << "  ";
    cout << '\n';
}