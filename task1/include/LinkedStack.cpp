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
		ListNode<T>* newOne = new ListNode(data);
		newOne->next = top;
		top = newOne;
	}

};