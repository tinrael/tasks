#include "Stack.cpp"
#include "ListNode.cpp"
#include <stdexcept>

template<typename T>
class LinkedStack : public Stack<T> {
private:
	ListNode<T>* top;
public:
	LinkedStack() {
		this->top = nullptr;
	}

	~LinkedStack() {
		ListNode<T>* current = top;
		ListNode<T>* toDelete;
		while (current) {
			toDelete = current;
			current = current->next;
			delete toDelete;
		}
	}

	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		return false;
	}

	void push(T data) override {
		ListNode<T>* newNode = new ListNode<T>(data);
		newNode->next = top;
		top = newNode;
	}

	T pop() override {
		if (isEmpty()) {
			throw std::logic_error("attempt to pop from an empty stack");
		}
		T result = top->data;
		ListNode<T>* toDelete = top;
		top = top->next;
		delete toDelete;
		return result;
	}
};