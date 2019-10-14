#pragma once

#include "Queue.hxx"

template<typename T>
class ArrayQueue : public Queue<T> {
private:
	int head;
	int tail;
	int capacity;
	T* items;
	const int INITIAL_CAPACITY = 4;

	void growCapacity();
public:
	ArrayQueue();

	~ArrayQueue();

	bool isEmpty();

	int size();

	void enqueue(T data) override;

	T dequeue() override;
};