#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class CircList {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
	std::size_t size_ = 0;

public:
	CircList() = default;
	CircList(const CircList& other);
	CircList& operator=(const CircList& other);
	CircList(CircList&& other) noexcept;
	CircList& operator=(CircList&& other) noexcept;
	~CircList();

	bool empty() const noexcept;
	std::size_t size() const noexcept;

	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	void clear() noexcept;

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
};

#include "CircList.tpp"
