#ifndef DSList_h__
#define DSList_h__

template <typename T>
class DSList
{
private:
	struct Node
	{

	};

public:
	class const_iterator
	{

	};

	class iterator : public const_iterator
	{

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

	void init();

private:
	int			_size;
	Node*		_head;
	Node*		_tail;
};






#endif // DSList_h__
