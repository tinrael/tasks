#include "ArrayStack.h"
#include <stdexcept>

template<typename T>
void ArrayStack<T>::growCapacity() {
	capacity *= 2;
	T* newItems = new T[capacity];
	for (int i = 0; i < size; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
}

template<typename T>
ArrayStack<T>::ArrayStack() {
	items = new T[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	size = 0;
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
	delete[] items;
}

template<typename T>
bool ArrayStack<T>::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

template<typename T>
void ArrayStack<T>::push(T data) {
	if (size == capacity) {
		growCapacity();
	}
	items[size] = data;
	size++;
}

template<typename T>
T ArrayStack<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("attempt to pop from an empty stack");
	}
	size--;
	return items[size];
}
