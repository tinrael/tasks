template<typename T>
class Stack {
public:
	virtual void push(T data) = 0;
	virtual T pop() = 0;
};