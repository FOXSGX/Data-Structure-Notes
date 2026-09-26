#pragma once

#include <iostream>
#include "LinearList.h"

template <class T>
class SeqList : public LinearList<T> {
private:
    T *data;
    int maxSize;
    int last;
    void reSize(int newSize);
public:
    SeqList(int size = 10);
    ~SeqList() override;
    SeqList(const SeqList<T>& L);
    SeqList(SeqList<T>&& L) noexcept;
    int Size() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int Length() const override;
    T *getData(int i) const override;
    void setData(int i, const T& x) override;
    bool Find(int k, T& x) const;
    int Search(const T& x) const override;
    void Insert(int k, const T& x) override;
    void Remove(int k) override;
    void Output(std::ostream& out) const;
    SeqList<T>& operator=(const SeqList<T>& L);
    SeqList<T>& operator=(SeqList<T>&& L) noexcept;
};

#include "SeqList.tpp"
