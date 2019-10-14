#pragma once

#include "Queue.hxx"
#include "ListNode.hxx"

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