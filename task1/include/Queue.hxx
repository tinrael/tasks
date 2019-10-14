#pragma once

template<typename T>
class Queue {
public:
	virtual void enqueue(T data) = 0;
	virtual T dequeue() = 0;
};