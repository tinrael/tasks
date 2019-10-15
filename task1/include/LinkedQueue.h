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

	void enQueue(T data) override;

	T deQueue() override;
};

#include "LinkedQueue.hxx"