#pragma once

template <class T>
class LinearList {
public:
    LinearList() = default;
    virtual ~LinearList() = default;
    virtual int Size() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual int Length() const = 0;
    virtual T *getData(int i) const = 0;
    virtual void setData(int i, const T& x) = 0;
    virtual int Search(const T& x) const = 0;
    virtual void Insert(int k, const T& x) = 0;
    virtual void Remove(int k) = 0;
};
