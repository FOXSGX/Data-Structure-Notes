#pragma once

template <typename T>
CircList<T>::CircList(const CircList& other)
{
	try {
		Node* current = other.head_;
		for (std::size_t i = 0; i < other.size_; ++i) {
			push_back(current->data);
			current = current->next;
		}
	} catch (...) {
		clear();
		throw;
	}
}

template <typename T>
CircList<T>& CircList<T>::operator=(const CircList& other)
{
	if (this == &other) {
		return *this;
	}

	CircList temp(other);
	std::swap(head_, temp.head_);
	std::swap(tail_, temp.tail_);
	std::swap(size_, temp.size_);
	return *this;
}

template <typename T>
CircList<T>::CircList(CircList&& other) noexcept
	: head_(other.head_), tail_(other.tail_), size_(other.size_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.size_ = 0;
}

template <typename T>
CircList<T>& CircList<T>::operator=(CircList&& other) noexcept
{
	if (this == &other) {
		return *this;
	}

	clear();
	head_ = other.head_;
	tail_ = other.tail_;
	size_ = other.size_;

	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.size_ = 0;
	return *this;
}

template <typename T>
CircList<T>::~CircList()
{
	clear();
}

template <typename T>
bool CircList<T>::empty() const noexcept
{
	return size_ == 0;
}

template <typename T>
std::size_t CircList<T>::size() const noexcept
{
	return size_;
}

template <typename T>
void CircList<T>::push_front(const T& value)
{
	Node* node = new Node{value, nullptr};

	if (empty()) {
		head_ = node;
		tail_ = node;
		node->next = node;
	} else {
		node->next = head_;
		head_ = node;
		tail_->next = head_;
	}

	++size_;
}

template <typename T>
void CircList<T>::push_back(const T& value)
{
	Node* node = new Node{value, nullptr};

	if (empty()) {
		head_ = node;
		tail_ = node;
		node->next = node;
	} else {
		node->next = head_;
		tail_->next = node;
		tail_ = node;
	}

	++size_;
}

template <typename T>
void CircList<T>::pop_front()
{
	if (empty()) {
		throw std::out_of_range("pop_front on empty CircList");
	}

	Node* oldHead = head_;
	if (size_ == 1) {
		head_ = nullptr;
		tail_ = nullptr;
	} else {
		head_ = head_->next;
		tail_->next = head_;
	}

	delete oldHead;
	--size_;
}

template <typename T>
void CircList<T>::pop_back()
{
	if (empty()) {
		throw std::out_of_range("pop_back on empty CircList");
	}

	Node* oldTail = tail_;
	if (size_ == 1) {
		head_ = nullptr;
		tail_ = nullptr;
	} else {
		Node* current = head_;
		while (current->next != tail_) {
			current = current->next;
		}
		tail_ = current;
		tail_->next = head_;
	}

	delete oldTail;
	--size_;
}

template <typename T>
void CircList<T>::clear() noexcept
{
	while (!empty()) {
		Node* oldHead = head_;
		if (size_ == 1) {
			head_ = nullptr;
			tail_ = nullptr;
		} else {
			head_ = head_->next;
			tail_->next = head_;
		}

		delete oldHead;
		--size_;
	}
}

template <typename T>
T& CircList<T>::front()
{
	if (empty()) {
		throw std::out_of_range("front on empty CircList");
	}
	return head_->data;
}

template <typename T>
const T& CircList<T>::front() const
{
	if (empty()) {
		throw std::out_of_range("front on empty CircList");
	}
	return head_->data;
}

template <typename T>
T& CircList<T>::back()
{
	if (empty()) {
		throw std::out_of_range("back on empty CircList");
	}
	return tail_->data;
}

template <typename T>
const T& CircList<T>::back() const
{
	if (empty()) {
		throw std::out_of_range("back on empty CircList");
	}
	return tail_->data;
}
