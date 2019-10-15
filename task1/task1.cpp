#include "include/ArrayQueue.h"
#include <iostream>

int main()
{
	Queue<int>* myQueue = new ArrayQueue<int>();
	myQueue->enqueue(1);
	myQueue->enqueue(2);
	myQueue->enqueue(3);
	std::cout << myQueue->dequeue() << std::endl;
	std::cout << myQueue->dequeue() << std::endl;
	std::cout << myQueue->dequeue() << std::endl;
	myQueue->enqueue(4);
	myQueue->enqueue(5);
	myQueue->enqueue(6);
	std::cout << myQueue->dequeue() << std::endl;
	std::cout << myQueue->dequeue() << std::endl;
	std::cout << myQueue->dequeue() << std::endl;
}