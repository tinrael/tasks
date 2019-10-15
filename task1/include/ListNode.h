#pragma once

template<typename T>
class ListNode {
public:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;

	ListNode(T data);
};

#include "ListNode.hxx"