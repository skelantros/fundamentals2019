#pragma once
#include "qSort.h"
#include "binarySearch.h"

template <typename Type>
class Vector
{
private:
	size_t _size;
	size_t _capacity;
	Type* _data;
	bool _is_sorted;
public:
	Vector(size_t capacity = 0);
	Vector(const Vector& vec);
	~Vector() { clear(); }

	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
	int find(Type elem) const;

	void clear();
	void empty();
	void sort();

	Vector& operator=(const Vector& vec);
	Type& operator[](size_t idx);
	Vector& push_back(const Type& elem);
	Vector& resize(size_t new_size);

	Vector(Vector&& vec);
	Vector& operator=(Vector&& right);

	class iterator
	{
	private:
		Type* _element;
	public:
		iterator(Type* elem = nullptr) : _element(elem) {}
		Type& operator*() { return *_element; }
		Type& operator*() const { return *_element; }
		bool operator==(const iterator& it) const
		{
			return _element == it._element;
		}
		bool operator!=(const iterator& it) const
		{
			return !(*this == it);
		}
		iterator& operator++()
		{
			++_element;
			return *this;
		}
		iterator operator++(int)
		{
			Type* tmp = _element;
			++_element;
			return iterator(tmp);
		}
	};

	iterator begin() const { return iterator(_data); }
	iterator end() const { return iterator(_data + _size); }

	class reverse_iterator {
	private:
		Type* _element;
	public:
		reverse_iterator(Type* elem = nullptr) : _element(elem) {}
		Type& operator*() { return *_element; }
		Type& operator*() const { return *_element; }
		bool operator==(const reverse_iterator& it) const { return _element == it._element; }
		bool operator!=(const reverse_iterator& it) const { return !(*this == it); }

		reverse_iterator& operator++()
		{
			--_element;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			Type* tmp = _element;
			--_element;
			return reverse_iterator(tmp);
		}
	};
	reverse_iterator rbegin() const { return reverse_iterator(_data + _size - 1); }
	reverse_iterator rend() const { return reverse_iterator(_data - 1); };
};

template <typename Type>
void Vector<Type>::sort()
{
	QSort(_data, _size);
	_is_sorted = true;
}

template <typename Type>
int Vector<Type>::find(Type elem) const
{
	if (_is_sorted)
		return binary_search(_data, elem, _size);
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == elem)
			return i;
	}
	return -1;
}

template <typename Type>
Vector<Type>::Vector(size_t capacity) : _size(0),
_capacity(capacity),
_data(nullptr),
_is_sorted(true)
{
	if (capacity > 0)
	{
		_data = new Type[capacity];
		if (!_data) throw "Out of memory";
	}
}

template <typename Type>
Vector<Type>::Vector(const Vector& vec) : _size(vec._size),
_capacity(vec._capacity),
_data(nullptr),
_is_sorted(vec._is_sorted)
{
	if (capacity > 0)
	{
		_data = new Type[capacity];
		if (!_data) throw "Out of memory";
		memcpy_s(_data, _capacity * sizeof(Type), vec._data, _capacity * sizeof(Type));
	}
}

template <typename Type>
void Vector<Type>::clear()
{
	if (_data) delete[] _data;
	_data = nullptr;
	_size = _capacity = 0;
}

template <typename Type>
void Vector<Type>::empty()
{
	_size = 0;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector& vec)
{
	if (this != &vec)
	{
		_size = vec._size;
		_capacity = vec._capacity;
		_is_sorted = vec._is_sorted;
		if (_data) delete[] _data;
		_data = new Type[_capacity];
		if (!_data) throw "Out of memory";
		for (int i = 0; i < _size; ++i)
			_data[i] = vec._data[i];
	}
	return *this;
}

template<typename Type>
Type& Vector<Type>::operator[](size_t idx)
{
	if (idx >= _size) throw "Out of bounds";
	_is_sorted = false;
	return _data[idx];
}

template<typename Type>
Vector<Type>& Vector<Type>::push_back(const Type& elem)
{
	if (_size == _capacity)
	{
		if (_capacity < 10)
			resize(_capacity + 10);
		else
			resize(_capacity * 1.5);
		//resize(_capacity < 10 ? _capacity + 10 : 1.5*_capacity);
	}
	_data[_size++] = elem;
	if (_size > 1 && _data[_size - 1] < _data[_size - 2])
		_is_sorted = false;
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::resize(size_t new_size)
{
	_capacity = new_size;
	_size = _capacity < _size ? _capacity : _size;
	Type* tmp = new Type[_capacity];
	if (!tmp) throw "Out of memory";
	for (int i = 0; i < _size; ++i)
		//tmp[i] = _data[i];
		tmp[i] = std::move(_data[i]);
	if (!_data)
		delete[] _data;
	_data = tmp;
}

template<typename Type>
Vector<Type>::Vector(Vector&& vec)
{
	_size = vec._size;
	_capacity = vec._capacity;
	_is_sorted = vec._is_sorted;
	_data = vec._data;
	vec._data = 0;
	vec._size = 0;
	vec._capacity = 0;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(Vector&& right)
{
	if (this != &right)
	{
		_size = right._size;
		_capacity = right._capacity;
		/*_data = new Type[_capacity];
		if (!_data) throw "Out of memory";
		for (int i = 0; i < _size; ++i)
			_data[i] = vec._data[i];*/
		if (!_data) delete[] _data;
		_data = right._data;
		right._data = 0;
		right._size = 0;
		right._capacity = 0;
		_is_sorted = right._is_sorted;
	}
	return *this;
}