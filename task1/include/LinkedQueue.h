#pragma once

#include "Queue.h"
#include "ListNode.h"

template<typename T>
class LinkedQueue : public Queue<T> {
private:
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	LinkedQueue();

	~LinkedQueue();

	bool isEmpty();

	void enqueue(T data) override;

	T dequeue() override;
};

#include "LinkedQueue.hxx"