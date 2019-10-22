#include "LinkedQueue.h"
#include <stdexcept>

template<typename T>
LinkedQueue<T>::LinkedQueue() {
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
	ListNode<T>* current = head;
	ListNode<T>* toDelete;
	while (current) {
		toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}

template<typename T>
void LinkedQueue<T>::enqueue(T data) {
	ListNode<T>* newNode = new ListNode<T>(data);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}		
}

template<typename T>
T LinkedQueue<T>::dequeue() {
	if (isEmpty()) {
		throw std::logic_error("attempt to dequeue from an empty queue");
	}
	T result = head->data;
	ListNode<T>* toDelete = head;
	head = head->next;
	delete toDelete;
	// if it is the last node, tail will point to freed memory
	if (head == nullptr) {
		tail = nullptr;
	}
	return result;
}