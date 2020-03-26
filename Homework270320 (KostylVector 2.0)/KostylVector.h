#pragma once
#include <iostream>

template <typename T>
class KostylVector
{
private:
	int _size, _capacity;
	T* _arr;
	void init(int capacity)
	{
		_capacity = capacity;
		_size = 0;
		_arr = new T[_capacity];
	}
public:
	KostylVector(int capacity)
	{
		init(capacity);
	}
	KostylVector(int capacity, T val) : KostylVector(capacity)
	{
		_size = capacity;
		for (int i = 0; i < capacity; ++i)
			_arr[i] = val;
	}
	KostylVector(const KostylVector& source) : KostylVector(source._size)
	{
		_size = source._size;
		for (int i = 0; i < _size; ++i)
			_arr[i] = source._arr[i];
	}

	KostylVector* pushBack(T val)
	{
		if (_size < _capacity)
			_arr[_size++] = val;
		else
		{
			T* tmp_arr = new T[2 * _capacity];
			memcpy_s(tmp_arr, sizeof(T) * 2 * _capacity, _arr, sizeof(T) * _capacity);
			tmp_arr[_capacity] = val;
			_size = _capacity + 1;
			_capacity *= 2;
			delete[] _arr;
			_arr = tmp_arr;
		}
		return this;
	}

	T& at(int idx)
	{
		if (idx < 0 || idx >= _size)
			throw "Error: index out of range";
		return _arr[idx];
	}

	T& operator[](int idx)
	{
		return at(idx);
	}

	void print()
	{
		for (int i = 0; i < _size; ++i)
			std::cout << _arr[i] << ' ';
		std::cout << std::endl;
	}

	~KostylVector()
	{
		delete[] _arr;
	}
};