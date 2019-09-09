#ifndef ArrayStack_h__
#define ArrayStack_h__

#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayStack
{

	friend std::ostream& operator<<(std::ostream& os, const ArrayStack& a)
	{
		for (int i = a._topOfStack; i >= 0; --i)
			os << a._stackArray[i] << " ";
		return os;
	}

public:
	ArrayStack(int initSize = 100);
	~ArrayStack();

	ArrayStack& operator=(const ArrayStack<T>&) = delete;

	void push(const T& x);
	void push(T&& x);

	void pop();
	
	T& top();
	const T& top() const;
	
	bool isEmpty() const
	{
		return (_topOfStack == -1);
	}

	bool isFull() const
	{
		return _topOfStack == (_stackCapacity-1);
	}

private:
	int	_topOfStack;
	int	_stackCapacity;
	T*	_stackArray;
};


template <typename T>
ArrayStack<T>::ArrayStack(int initSize /*= 100*/) : 
	_topOfStack(-1), 
	_stackCapacity(initSize)
{
	_stackArray = new T[_stackCapacity];
}


template <typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] _stackArray;
	_stackArray = nullptr;
	_stackCapacity = 0;
	_topOfStack = -1;
}


template <typename T>
void ArrayStack<T>::push(const T& x)
{
	if (isFull())
		throw std::overflow_error("stack over flow");
	_stackArray[++_topOfStack] = x;
}


template <typename T>
void ArrayStack<T>::push(T&& x)
{
	if (isFull())
		throw std::overflow_error("stack over flow");
	_stackArray[++_topOfStack] = std::move(x);
}


template <typename T>
void ArrayStack<T>::pop()
{
	if (isEmpty())
		throw std::underflow_error("stack under flow");
	--_topOfStack;
}


template <typename T>
T& ArrayStack<T>::top()
{
	if (isEmpty())
		throw std::underflow_error("stack under flow");
	return _stackArray[_topOfStack];
}



template <typename T>
const T& ArrayStack<T>::top() const
{
	if (isEmpty())
		throw std::underflow_error("stack under flow");
	return _stackArray[_topOfStack];
}

#endif // ArrayStack_h__
