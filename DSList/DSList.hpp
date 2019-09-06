#ifndef DSList_h__
#define DSList_h__

#include <utility>
#include <iostream>


template <typename T>
class DSList
{

	friend void swap(DSList<T>& left, DSList<T>& right);

private:
	struct Node
	{
		T 			_data;
		Node*		_prev;
		Node*		_next;

		Node(const T& d = T{}, Node* prev = nullptr, Node* next = nullptr) :
			_data{d}, _prev{prev}, _next{next}{ }

		Node(T&& d, Node *prev = nullptr, Node* next = nullptr) :
			_data{std::move(d)}, _prev(prev), _next(next){ }
	};


public:
	class const_iterator
	{
	public:
		const_iterator() : _current{nullptr}{ }

		const T& operator*() const
		{
			return retrieve();
		}

		const_iterator& operator++()
		{
			_current = _current->_next;
			return *this;
		}
		
		const_iterator& operator--()
		{
			this->_current = this->_current->_prev;
			return *this;
		}

		const_iterator& operator--(int)
		{
			const_iterator old = *this;
			--(*this);
			return old;
		}

		const_iterator& operator++(int)	//post
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator& rhs) const
		{
			return _current == rhs._current;
		}
		bool operator!=(const const_iterator& rhs) const
		{
			return !((*this) == rhs);
		}

		
	protected:
		Node*		_current;

		T& retrieve() const
		{
			return _current->_data;
		}

		const_iterator(Node* p) : _current(p){ }

		friend class DSList<T>;
	};


	class iterator : public const_iterator
	{
		public:
			iterator(){ }

			T& operator*()
			{
				return const_iterator::retrieve();
			}

			const T& operator*() const
			{
				return const_iterator::retrieve();
			}

			iterator& operator++()
			{
				this->_current = this->_current->_next;
				return *this;
			}

			iterator& operator--()
			{
				this->_current = this->_current->_prev;
				return *this;
			}

			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

			iterator operator--(int)
			{
				iterator old = *this;
				--(*this);
				return old;
			}

		protected:
			iterator(Node *p) : const_iterator(p){ }

		friend class DSList<T>;
	};

public:
	DSList()
	{
		init();
	}

	DSList(const DSList& rhs) : _head(new Node()), _tail(new Node()), _size(0)
	{
		auto ptr = rhs.begin();
		while (ptr != rhs.end())
		{
			push_back(*ptr);
		}
	}

	~DSList()
	{
		clear();
		delete _head;
		_head = nullptr;
		delete _tail;
		_tail = nullptr;
	}

	DSList(DSList&& rhs)	
	{
		swap(*this, rhs);
	}


	DSList& operator=(DSList rhs) {
		swap(*this, rhs);
		return *this;
	}


	iterator begin()
	{
		return iterator(_head->_next);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_tail);
	}

	const_iterator end() const
	{
		return  const_iterator(_tail);
	}

	int size() const
	{
		return _size;
	}

	bool empty() const
	{
		return _size == 0;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	T& front()
	{
		return *begin();
	}
	const T& front() const
	{
		return *begin();
	}

	T& back()
	{
		return *(--end());
	}
	const T& back() const
	{
		return *(--end());
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	void push_front(T&& x)
	{
		insert(begin(), std::move(x));
	}

	void push_back(const T& x)
	{
		insert(end(), x);
	}

	void push_back(T&& x)
	{
		insert(end(), std::move(x));
	}

	void pop_front()
	{
		erase(begin());
	}

	void pop_back()
	{
		erase(--end());
	}

	iterator insert(iterator itr, const T& x)
	{
		Node* ptr = itr._current;
		Node* newNode = new Node(x, ptr->_prev, ptr);
		ptr->_prev->_next = newNode;
		ptr->_prev = newNode;

		++_size;
					
		return iterator(newNode);
	}

	iterator insert(iterator itr, T&& x)
	{
		Node* ptr = itr._current;
		Node* newNode = new Node(std::move(x), ptr->_prev, ptr);
		ptr->_prev->_next = newNode;
		ptr->_prev = newNode;

		++_size;
		return iterator(newNode);
	}

	iterator erase(iterator itr)
	{
		Node* ptr = itr._current;
		Node* ptrNext = ptr->_next;

		ptr->_prev->_next = ptr->_next;
		ptr->_next->_prev = ptr->_prev;

		delete ptr;
		--_size;

		return iterator(ptrNext);
	}


	iterator erase(iterator from, iterator to)
	{
		for (iterator itr = from; itr != to;)
			itr = erase(itr);
		return to;
	}

private:
	void init()
	{
		_size = 0;

		_head = new Node();
		_tail = new Node();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

private:
	int			_size;
	Node*		_head;
	Node*		_tail;
};


template<typename T>
void swap(DSList<T>& left, DSList<T>& right)
{
	std::swap(left._size, right._size);
	std::swap(left._head, right._head);
	std::swap(left._tail, right._tail);
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const DSList<T>& dslist)
{
	for (auto itr = dslist.begin(); itr != dslist.end(); ++itr)
	{
		os << *itr << " ";
	}

	return os;
}



#endif // DSList_h__
