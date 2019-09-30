#include <stdexcept>
#include "Stack.cpp"

template<typename T>
class ArrayStack : public Stack<T> {
private:
	int size;
	int capacity;
	T* items;
	const int INITIAL_CAPACITY = 4;

	void growCapacity() {
		capacity *= 2;
		T* newItems = new T[capacity];
		for (int i = 0; i < size; i++) {
			newItems[i] = items[i];
		}
		delete [] items;
		items = newItems;
	}
public:
	ArrayStack() {
		items = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;
		size = 0;
	}

	~ArrayStack() {
		delete [] items;
	}

	bool isEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}

	void push(T data) override {
		if (size == capacity) {
			growCapacity();
		}
		items[size] = data;
		size++;
	}

	T pop() override {
		if (isEmpty()) {
			throw std::logic_error("attempt to pop from an empty stack");
		}
		size--;
		return items[size];
	}
};