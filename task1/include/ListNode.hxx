#include "ListNode.h"

template<typename T>
ListNode<T>::ListNode(T data) {
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}