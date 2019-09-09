#ifndef LinkedStack_h__
#define LinkedStack_h__

template<typename T>
class LinkedStack
{
	struct Node 
	{
		Node(T val = T{}, Node* next = nullptr) : _val{ val }, _next{ next } { }
	
		T		_val;
		Node*	_next;
	};

	friend std::ostream& operator<<(std::ostream& os, const LinkedStack& a)
	{
		Node* ptr = a._head->_next;
		
		while (ptr)
		{
			os << ptr->_val << " ";
			ptr = ptr->_next;
		}

		return os;
	}

public:
	LinkedStack() : _size(0)
	{ 
		_head = new Node();
	}

	~LinkedStack()
	{ 
		while (!isEmpty())
		{
			pop();
		}
		delete _head;
		_head = nullptr;
	}

	LinkedStack& operator=(const LinkedStack<T>& other) = delete;
	LinkedStack(const LinkedStack<T>& other) = delete;

	void push(const T& x)
	{
		Node* node = new Node(x);
		node->_next = _head->_next;
		_head->_next = node;
		++_size;
	}

	void push(T&& x)
	{
		Node* node = new Node{ std::move(x) };
		node->_next = _head->_next;
		_head->_next = node;
		++_size;
	}

	void pop()
	{
		if (0 == _size)
			throw std::underflow_error("stack under flow");
		Node* firstNode = _head->_next;
		_head->_next = firstNode->_next;
		delete firstNode;
		--_size;
	}

	T& top() 
	{ 
		if (0 == _size)
			throw std::underflow_error("stack under flow");
		return _head->_next->_val;
	}

	const T& top() const
	{
		if (0 == _size)
			throw std::underflow_error("stack under flow");
		return _head->_next->_val;
	}

	bool isEmpty() const
	{
		return _size == 0;
	}

private:
	Node*	_head;
	int		_size;
};






#endif // LinkedStack_h__
