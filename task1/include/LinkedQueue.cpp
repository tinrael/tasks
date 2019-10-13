#include "Queue.cpp"
#include "ListNode.cpp"
#include <stdexcept>

template<typename T>
class LinkedQueue : public Queue<T> {
private:
	ListNode<T>* head;
	ListNode<T>* tail;	
public:
	LinkedQueue() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	~LinkedQueue() {
		ListNode<T>* current = head;
		ListNode<T>* toDelete;
		while (current) {
			toDelete = current;
			current = current->next;
			delete toDelete;
		}
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}

	void enQueue(T data) override {
		ListNode<T>* newNode = new ListNode<T>(data);
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}		
	}

	T deQueue() override {
		if (isEmpty()) {
			throw std::logic_error("attempt to dequeue from an empty queue");
		}
		T result = head->data;
		ListNode<T>* toDelete = head;
		head = head->next;
		delete toDelete;
		// if it is the last node, tail will point to freed memory
		if (head == nullptr) {
			tail = nullptr;
		}
		return result;
	}
};