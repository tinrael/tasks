template<typename T>
class Queue {
public:
	virtual void enQueue(T data) = 0;
	virtual T deQueue() = 0;
};