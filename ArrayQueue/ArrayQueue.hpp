#ifndef ArrayQueue_h__
#define ArrayQueue_h__

#include <stdexcept>
const int InitQueueCapacity = 10;

#if 0


template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(int capacity = InitQueueCapacity) : _capacity(capacity)
	{
		_theArray = new T[_capacity];
		_frontIndex = 0;
		_rearIndex = (_capacity - 1);
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
		
		_rearIndex = (_rearIndex + 1) % _capacity;
		_theArray[_rearIndex] = e;
		++_currentSize;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			throw std::underflow_error("queue_empty");
		}
		T tmp = _theArray[_frontIndex];
		
		_frontIndex = (_frontIndex + 1) % _capacity;

		--_currentSize;
		return tmp;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have a front!");
		}
		return _theArray[_frontIndex];
	}

	const T& rear() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have a rear!");
		}
		return _theArray[_rearIndex];
	}

	int size()
	{
		return _currentSize;
	}

	bool isEmpty() const
	{
		return (_currentSize == 0);
	}
	
	bool isFull()
	{
		return (_currentSize == _capacity);
	}

protected:
	T*		_theArray;
	int		_frontIndex;
	int		_rearIndex;
	int		_currentSize;
	int		_capacity;
};
#endif





//////////////////////////////////////////////////////////////////////////
//ArrayQueue初值的_frontIndex和_rearIndex都设置为0 (NOT A GOOD PRACTICE !!!)

#if 0
template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(int capacity = InitQueueCapacity) : _capacity(capacity)
	{
		_theArray = new T[_capacity];
		_frontIndex = 0;
		_rearIndex = 0;
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

		if (isEmpty())
		{
			_theArray[0] = e;
		}
		else
		{
			_rearIndex = (_rearIndex + 1) % _capacity;
			_theArray[_rearIndex] = e;
		}

		++_currentSize;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			throw std::underflow_error("queue_empty");
		}
		T tmp = _theArray[_frontIndex];

		_frontIndex = (_frontIndex + 1) % _capacity;

		--_currentSize;
		return tmp;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have a front!");
		}
		return _theArray[_frontIndex];
	}

	const T& rear() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have a rear!");
		}
		return _theArray[_rearIndex];
	}

	int size()
	{
		return _currentSize;
	}

	bool isEmpty() const
	{
		return (_currentSize == 0);
	}

	bool isFull()
	{
		return (_currentSize == _capacity);
	}

protected:
	T* _theArray;
	int		_frontIndex;
	int		_rearIndex;
	int		_currentSize;
	int		_capacity;
};

#endif


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///后指针指向队列尾部的后一个位置并且包含队列大小size成员
#if 0

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(int initSize = InitQueueCapacity) : _capacity(initSize)
	{
		_theArray = new T[_capacity];
		_front = 0;
		_rear = 0;
		_size = 0;
	}

	~ArrayQueue()
	{
		delete[] _theArray;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have front");
		}
		return _theArray[_front];
	}

	const T& rear() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have rear");
		}
		int index = (_rear - 1 + _capacity)%_capacity;
		return _theArray[index];
	}

	bool isEmpty() const
	{
		return (0 == _size);
	}

	bool isFull() const
	{
		return (_capacity == _size);
	}

	void enqueue(const T& e)
	{
		if (isFull())
		{
			throw std::overflow_error("full queue can not enqueue!");
		}
		_theArray[_rear] = e;
		_rear = (_rear + 1) % _capacity;
		++_size;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue can not dequeue!");
		}

		_front = (_front + 1) % _capacity;
		--_size;
	}


private:
	int	_capacity;
	int	_size;
	int	_front;
	int	_rear;
	T* _theArray;
};
#endif



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//后指针指向队列尾部的元素（队列的最后一个元素），不包含队列大小size成员
//
//template <typename T>
//class ArrayQueue
//{
//public:
//	ArrayQueue(int capacity = InitQueueCapacity) : _capacity(capacity)
//	{
//		_front = 0;
//		_rear = capacity - 1;
//		_theArray = new T[_capacity];
//	}
//
//	~ArrayQueue()
//	{
//		delete[] _theArray;
//	}
//
//	bool isEmpty() const
//	{
//		return (((_rear + 1) % _capacity) == _front);
//	}
//
//	bool isFull() const
//	{
//		return (((_rear + 2) % _capacity) == _front);
//	}
//
//	int size() const
//	{
//		return (rear + _capacity - _front + 1) % _capacity;
//	}
//
//	int capacity() const
//	{
//		return (_capacity - 1);
//	}
//
//	const T& front() const
//	{
//		if (isEmpty())
//		{
//			throw std::underflow_error("empty queue do not have front.");
//		}
//
//		return _theArray[_front];
//	}
//
//	const T& rear() const
//	{
//		if (isEmpty())
//		{
//			throw std::underflow_error("empty queue do not have rear.");
//		}
//		return _theArray[_rear];
//	}
//
//	void enqueue(const T& e)
//	{
//		if (isFull())
//		{
//			throw std::overflow_error("queue is full, can not enqueue.");
//		}
//		int index = ((_rear + 1) % _capacity);
//		_theArray[index] = e;
//		_rear = index;
//	}
//
//
//	void dequeue()
//	{
//		if (isEmpty())
//		{
//			throw std::underflow_error("empty queue can not dequeue.");
//		}
//		_front = ((_front + 1) % _capacity);
//	}
//
//
//
//
//private:
//	int _capacity;
//	int _front;
//	int _rear;
//	T* _theArray;
//};
//
//



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// 不包含size成员，后指针指向队列尾部元素的下一个位置

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(int initCapacity = InitQueueCapacity) : _capacity(initCapacity)
	{
		_theArray = new T[initCapacity];
		_front = 0;
		_rear = 0;
	}

	~ArrayQueue()
	{
		delete[] _theArray;
	}

	bool isEmpty() const
	{
		return (_rear == _front);
	}

	bool isFull() const
	{
		return ((_rear + 1) % _capacity) == _front;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have front.");
		}
		return _theArray[_front];
	}

	const T& rear() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue do not have rear.");
		}
		int lastElementIndex = (_rear - 1 + _capacity) % _capacity;
		return _theArray[lastElementIndex];
	}

	void enqueue(const T& e)
	{
		if (isFull())
		{
			throw std::overflow_error("queue is full can not queue.");
		}
		_theArray[_rear] = e;
		_rear = (_rear + 1) % _capacity;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			throw std::underflow_error("queue is empty can not queue.");
		}
		_front = (_front + 1) % _capacity;
	}


private:
	int _capacity;
	int _front;
	int _rear;
	T* _theArray;
};



#endif // ArrayQueue_h_

