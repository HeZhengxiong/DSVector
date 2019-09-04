#ifndef DSVector_h__
#define DSVector_h__

#include <algorithm>
#include <iostream>
#include <assert.h>

template<typename T>
class DSVector
{
	template<typename T>
	friend	void swap(DSVector<T>& left, DSVector<T>& right)
	{
		using std::swap;
		swap(left._size, right._size);
		swap(left._capacity, right._capacity);
		swap(left._array, right._array);
	}


public:

	static const int SPARE_CAPACITY = 16;

	explicit DSVector(int initSize = 0) :
		_size(initSize), 
		_capacity(_size + SPARE_CAPACITY),
		_array(new T[_capacity]) 
		//caution: sequence of data member: based on the defined sequence in class not 
		//sequence in init list.
	{
	}

	~DSVector()
	{
		delete [] _array;
		_array = nullptr;
		_size = 0;
		_capacity = 0;
	}
	
	DSVector(const DSVector& rhs) : _size(rhs._size), _capacity(rhs._capacity)
	{
		_array = new T[_capacity];
		for (int i = 0; i < _size; ++i)
		{
			_array[i] = rhs._array[i];
		}
	}

	DSVector(DSVector&& rhs) : DSVector()
	{
		swap(*this, rhs);
	}

	//copy-swap-idiom
	DSVector& operator=(DSVector rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	void resize(int newSize)
	{
		if (newSize > _capacity)
			reserve(newSize * 2);

		_size = newSize;
	}

	void reserve(int capacity)
	{
		if (capacity < _capacity)
			return;

		T* newArray = new T[capacity];
		for (int i = 0; i < _size; ++i)
		{
			newArray[i] = std::move(_array[i]);
		}

		_capacity = capacity;
		std::swap(_array, newArray);
		delete[] newArray;
	}

	bool isEmpty() const
	{
		return (_size == 0);
	}

	int size() const
	{
		return _size;
	}

	int capacity() const
	{
		return _capacity;
	}

	T& operator[](int index)
	{
		return _array[index];
	}

	const T& operator[](int index) const
	{
		return _array[index];
	}

	void push_back(const T& x)
	{
		if (_size == _capacity)
			reserve(_size * 2 + 1);
		_array[_size++] = x;
	}

	void push_back(T&& x)
	{
		if (_size == _capacity)
			reserve(_size * 2 + 1);
		_array[_size++] = std::move(x);
	}

	void pop_back()
	{
		--_size;
	}

	const T& back() const
	{
		return _array[_size - 1];
	}

	void insert(int index, const T& v)
	{
		assert(index >= 0 && index <= _size);

		if (_size == _capacity)
			reserve(_size * 2 + 1);

		for (int i = _size; i > index; --i)
		{
			_array[i] = _array[i - 1];
		}

		_array[index] = v;
		++_size;
	}

	void insert(int index, T&& v)
	{
		assert(index >= 0 && index <= _size);
		if (_size == _capacity)
			reserve(_size * 2 + 1);

		for (int i = _size; i > index; --i)
		{
			_array[i] = _array[i - 1];
		}

		_array[index] = std::move(v);
		++_size;

	}

	void erase(int index)
	{
		assert(index >= 0 && index < _size);

		for (int i = index; i < (_size - 1); ++i)
		{
			_array[i] = _array[i + 1];
		}
		--_size;
	}

	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return &_array[0];
	}

	iterator end()
	{
		return _array + _size;
	}

	const_iterator	begin() const
	{
		return &_array[0];
	}

	const_iterator	end() const
	{
		return _array + _size;
	}


private:
	int		_size;
	int		_capacity;
	T*		_array;
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const DSVector<T>& v)
{
	for (auto iter = v.begin(); iter != v.end(); )
	{
		os << (*iter++) << " ";
	}

	return os;
}



#endif // DSVector_h__
