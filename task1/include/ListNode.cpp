template<typename T>
class ListNode {
public:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;

	ListNode(T data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};