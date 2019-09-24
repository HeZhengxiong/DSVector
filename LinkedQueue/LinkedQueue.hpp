#pragma once

#include <stdexcept>


template <typename T>
class LinkedQueue
{
public:
	LinkedQueue()
	{
		_header = _tail = new Node();
		_size = 0;
	}

	~LinkedQueue()
	{
		clearQueue();
		delete _header;
		//delete _tail;		//tail指向的是真实的Queue元素，已经在clearQueue里面被清除了，此处加上delete是错误的
		_header = nullptr;
		_tail = nullptr;
		_size = 0;
	}

	bool isEmpty() const
	{
		return (0 == _size);
	}

	void enqueue(const T& item)
	{
		Node* insertedNode = new Node(item);
		_tail->_next = insertedNode;
		_tail = insertedNode;
		++_size;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue cannot dequeue!");
		}
		Node* firstNode = _header->_next;
		_header->_next = firstNode->_next;
		delete firstNode;
		--_size;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue don't have a front!");
		}
		Node* frontNode = _header->_next;
		return frontNode->_data;
	}

	const T& rear() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("empty queue don't have a tail!");
		}
		return _tail->_data;
	}

private:
	void clearQueue()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}
	
private:
	struct Node
	{
		Node* _next;
		T	  _data;

		Node(const T& e = T(), Node* next = nullptr) : _data{ e }, _next{ next }{ }
		Node(T&& e, Node* next = nullptr) : _data{ std::move(e) }, _next{ next }{}
	};

	Node* _header;
	Node* _tail;
	int	 _size;
};

