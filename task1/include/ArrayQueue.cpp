#include "Queue.cpp"
#include <stdexcept>

template<typename T>
class ArrayQueue : public Queue<T> {
private:
	int head;
	int tail;
	int capacity;
	T* items;
	const int INITIAL_CAPACITY = 4;

	void growCapacity() {

	}
public:
	ArrayQueue() {
		items = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;
		this->head = 0;
		this->tail = 0;
	}

	~ArrayQueue() {
		delete[] items;
	}

	bool isEmpty() {
		
	}

	void enqueue(T data) {
		
	}

	T dequeue() {
		
	}
};