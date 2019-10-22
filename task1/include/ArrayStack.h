#pragma once

#include "Stack.h"

template<typename T>
class ArrayStack : public Stack<T> {
private:
	int size;
	int capacity;
	T* items;
	const int INITIAL_CAPACITY = 4;

	void growCapacity();
public:
	ArrayStack();

	~ArrayStack();

	bool isEmpty();

	void push(T data) override;

	T pop() override;
};

#include "ArrayStack.hxx"