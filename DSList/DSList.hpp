#ifndef DSList_h__
#define DSList_h__

template <typename T>
class DSList
{
private:
	struct Node
	{
		T 			_data;
		Node*		_prev;
		Node*		_next;

		Node(const T& d = T{}, Node* prev = nullptr, Node* next = nullptr) :
			_data{d}, _prev{prev}, _next{next}{ }

		Node(T&& d, Node *prev = nullptr, Node* next = nullptr) :
			_data{std::move(d)}, _prev(prve), _next(next){ }
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
		const_iterator& operator++(int)	//post
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator& rhs) const
		{
			return _current = rhs._current;
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
				_current = _current->_next;
				return *this;
			}

			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

		protected:
			iterator(Node *p) : const_iterator(p){ }

		friend class DSList<T>;
	};

public:
	DSList();
	DSList(const DSList& rhs);
	~DSList();
	DSList& operator=(const DSList& rhs);
	DSList(DSList&& rhs);
	DSList& operator=(DSList&& rhs);

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	int size() const;
	bool empty() const;
	void clear();

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	void push_front(const T& x);
	void push_front(T&& x);
	void push_back(const T& x);
	void push_back(T&& x);
	void pop_front();
	void pop_back();

	iterator insert(iterator itr, const T& x);
	iterator insert(iterator itr, T&& x);

	iterator erase(iterator itr);
	iterator erase(iterator from, iterator to);

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






#endif // DSList_h__
