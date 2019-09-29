#include <stdexcept>
#include "Stack.cpp"
#include "ListNode.cpp"

template<typename T>
class LinkedStack : public Stack<T> {
private:
	ListNode<T>* top;
public:
	LinkedStack() {
		this->top = nullptr;
	}

	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		return false;
	}

	void push(T data) override {
		ListNode<T>* newNode = new ListNode(data);
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