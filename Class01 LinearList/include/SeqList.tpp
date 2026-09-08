#pragma once

#include "SeqList.h"

template <class T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize <= 0) {
        return;
    }

    T *newData = new T[newSize];
    int newLast = last < newSize ? last : newSize;
    for (int i = 0; i < newLast; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    maxSize = newSize;
    last = newLast;
}

template <class T>
SeqList<T>::SeqList(int size)
{
    if (size <= 0) {
        size = 10;
    }

    maxSize = size;
    last = 0;
    data = new T[maxSize];
}

template <class T>
SeqList<T>::~SeqList()
{
    delete[] data;
}

template <class T>
SeqList<T>::SeqList(const SeqList<T>& L)
{
    maxSize = L.maxSize;
    last = L.last;
    data = new T[maxSize];
    for (int i = 0; i < last; i++) {
        data[i] = L.data[i];
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T>&& L) noexcept
{
    data = L.data;
    maxSize = L.maxSize;
    last = L.last;

    L.data = nullptr;
    L.maxSize = 0;
    L.last = 0;
}

template <class T>
int SeqList<T>::Size() const
{
    return maxSize;
}

template <class T>
bool SeqList<T>::IsEmpty() const
{
    return last == 0;
}

template <class T>
bool SeqList<T>::IsFull() const
{
    return last == maxSize;
}

template <class T>
int SeqList<T>::Length() const
{
    return last;
}

template <class T>
T *SeqList<T>::getData(int i) const
{
    if (i < 1 || i > last) {
        return nullptr;
    }
    return &data[i - 1];
}

template <class T>
void SeqList<T>::setData(int i, const T& x)
{
    if (i < 1 || i > last) {
        return;
    }
    data[i - 1] = x;
}

template <class T>
bool SeqList<T>::Find(int k, T& x) const
{
    if (k < 1 || k > last) {
        return false;
    }
    x = data[k - 1];
    return true;
}

template <class T>
int SeqList<T>::Search(const T& x) const
{
    for (int i = 0; i < last; i++) {
        if (data[i] == x) {
            return i + 1;
        }
    }
    return 0;
}

template <class T>
void SeqList<T>::Insert(int k, const T& x)
{
    if (k < 1 || k > last + 1) {
        std::cerr << "illegal k" << std::endl;
        return;
    }
    if (IsFull()) {
        std::cerr << "the seqlist is full" << std::endl;
        return;
    }

    for (int i = last; i >= k; i--) {
        data[i] = data[i - 1];
    }
    data[k - 1] = x;
    last++;
}

template <class T>
void SeqList<T>::Remove(int k)
{
    if (k < 1 || k > last) {
        std::cerr << "illegal k" << std::endl;
        return;
    }

    for (int i = k - 1; i < last - 1; i++) {
        data[i] = data[i + 1];
    }
    last--;
}

template <class T>
void SeqList<T>::Output(std::ostream& out) const
{
    for (int i = 0; i < last; i++) {
        if (i > 0) {
            out << ' ';
        }
        out << data[i];
    }
}

template <class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& L)
{
    if (this == &L) {
        return *this;
    }

    T *newData = new T[L.maxSize];
    for (int i = 0; i < L.last; i++) {
        newData[i] = L.data[i];
    }

    delete[] data;
    data = newData;
    maxSize = L.maxSize;
    last = L.last;
    return *this;
}

template <class T>
SeqList<T>& SeqList<T>::operator=(SeqList<T>&& L) noexcept
{
    if (this == &L) {
        return *this;
    }

    delete[] data;
    data = L.data;
    maxSize = L.maxSize;
    last = L.last;

    L.data = nullptr;
    L.maxSize = 0;
    L.last = 0;
    return *this;
}
