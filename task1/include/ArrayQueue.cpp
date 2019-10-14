#include "ArrayQueue.hxx"
#include <stdexcept>

template<typename T>
void ArrayQueue<T>::growCapacity() {
	int count = size();
	int oldCapacity = capacity;
	capacity *= 2;
	T* newItems = new T[capacity];
	for (int i = 0; i < count; i++) {
		newItems[i] = items[head];
		head = (head + 1) % oldCapacity;
	}
	head = 0;
	tail = count;
	delete[] items;
	items = newItems;		
}

template<typename T>
ArrayQueue<T>::ArrayQueue() {
	head = 0;
	tail = 0;
	items = new T[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;	
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] items;
}

template<typename T>
bool ArrayQueue<T>::isEmpty() {
	return head == tail;
}

template<typename T>
int ArrayQueue<T>::size() {
	return (tail + capacity - head) % capacity;
}

template<typename T>
void ArrayQueue<T>::enqueue(T data) {
	if (size() == capacity - 1) {
		growCapacity();
	}
	items[tail] = data;
	tail = (tail + 1) % capacity;
}

template<typename T>
T ArrayQueue<T>::dequeue() {
	if (isEmpty()) {
		throw std::logic_error("attempt to dequeue from an empty queue");
	}
	T result = items[head];
	head = (head + 1) % capacity;
	return result;
}