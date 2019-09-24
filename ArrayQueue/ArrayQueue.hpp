#ifndef ArrayQueue_h__
#define ArrayQueue_h__

#include <stdexcept>

const int InitQueueCapacity = 100;

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(int capacity = InitQueueCapacity) : _capacity(capacity)
	{
		_theArray = new T[_capacity];
		_frontIndex = 0;
		_backIndex = (_capacity - 1);
		_currentSize = 0;
	}

	~ArrayQueue()
	{
		delete[] _theArray;
		_currentSize = 0;
		_capacity = 0;
	}
	
	void enqueue(const T& e)
	{
		if (isFull())
		{
			throw std::overflow_error("queue_full");
		}
		
		_backIndex = (_backIndex + 1) % _capacity;
		_theArray[_backIndex] = e;
		++_currentSize;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			std::underflow_error("queue_empty");
		}
		T tmp = _theArray[_frontIndex];
		
		_frontIndex = (_frontIndex + 1) % _capacity;

		--_currentSize;
		return tmp;
	}

	int size()
	{
		return _currentSize;
	}

	bool isEmpty()
	{
		return _currentSize == 0;
	}
	
	bool isFull()
	{
		return _currentSize == _capacity;
	}

protected:
	T*		_theArray;
	int		_frontIndex;
	int		_backIndex;
	int		_currentSize;
	int		_capacity;
};




#endif // ArrayQueue_h__
