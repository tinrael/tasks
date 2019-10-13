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
public:
	ArrayQueue() {
		head = 0;
		tail = 0;
		items = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;	
	}

	~ArrayQueue() {
		delete[] items;
	}

	bool isEmpty() {
		return head == tail;
	}

	int size() {
		return (tail + capacity - head) % capacity;
	}

	void enqueue(T data) override {
		if (size() == capacity - 1) {
			growCapacity();
		}
		items[tail] = data;
		tail = (tail + 1) % capacity;
	}

	T dequeue() override {
		if (isEmpty()) {
			throw std::logic_error("attempt to dequeue from an empty queue");
		}
		T result = items[head];
		head = (head + 1) % capacity;
		return result;
	}
};