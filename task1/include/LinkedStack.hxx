#include "LinkedStack.h"
#include <stdexcept>

template<typename T>
LinkedStack<T>::LinkedStack() {
	this->top = nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
	ListNode<T>* current = top;
	ListNode<T>* toDelete;
	while (current) {
		toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

template<typename T>
bool LinkedStack<T>::isEmpty() {
	if (top == nullptr) {
		return true;
	}
	return false;
}

template<typename T>
void LinkedStack<T>::push(T data) {
	ListNode<T>* newNode = new ListNode<T>(data);
	newNode->next = top;
	top = newNode;
}

template<typename T>
T LinkedStack<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("attempt to pop from an empty stack");
	}
	T result = top->data;
	ListNode<T>* toDelete = top;
	top = top->next;
	delete toDelete;
	return result;
}
