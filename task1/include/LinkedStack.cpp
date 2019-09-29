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
};