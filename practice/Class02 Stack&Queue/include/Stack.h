#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;
public:
    Stack() = default;

    explicit Stack(std::size_t n, const T& value = T());

    bool empty() const noexcept;

    std::size_t size() const noexcept;

    void push(const T& value);

    void push(T&& value);

    void pop();

    T& top();

    const T& top() const;

};

#include "Stack.tpp"

#endif
