#include <stdexcept>
#include "Queue.cpp"
#include "ListNode.cpp"

template<typename T>
class LinkedQueue : public Queue<T> {
private:
	ListNode<T>* tail;
	ListNode<T>* head;
public:
	LinkedQueue() {
		head = nullptr;
		tail = nullptr;
	}

	~LinkedQueue() {
		// TODO: delete queue
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}

	void enQueue(T data) override {
		ListNode<T>* newNode = ListNode<T>(data);
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
		if (head == nullptr) {
			tail = nullptr;
		}
		return result;
	}
};