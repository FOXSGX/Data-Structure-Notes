template <typename T>
Stack<T>::Stack(std::size_t n, const T& value)
    : data(n, value)
{
}

template <typename T>
bool Stack<T>::empty() const noexcept
{
    return data.empty();
}

template <typename T>
std::size_t Stack<T>::size() const noexcept
{
    return data.size();
}

template <typename T>
void Stack<T>::push(const T& value)
{
    data.push_back(value);
}

template <typename T>
void Stack<T>::push(T&& value)
{
    data.push_back(std::move(value));
}

template <typename T>
void Stack<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    data.pop_back();
}

template <typename T>
T& Stack<T>::top()
{
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

template <typename T>
const T& Stack<T>::top() const
{
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}
