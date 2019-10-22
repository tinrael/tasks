#pragma once

#include "Stack.h"
#include "ListNode.h"

template<typename T>
class LinkedStack : public Stack<T> {
private:
	ListNode<T>* top;
public:
	LinkedStack();

	~LinkedStack();

	bool isEmpty();

	void push(T data) override;

	T pop() override;
};

#include "LinkedStack.hxx"