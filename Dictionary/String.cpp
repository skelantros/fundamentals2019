#include "String.h"

String::String(const char* str)
{
	_size = strlen(str) + 1;
	_data = new char[_size];
	memcpy_s(_data, _size, str, _size);
}

String::String(int size)
{
	_size = size;
	if (_size <= 0)
		throw "Error: wrong size while creating string";
	_data = new char[_size];
	_data[0] = 0;
}

String::String(const String& src)
{
	_data = new char[src._size];
	_size = src._size;
	memcpy_s(_data, _size, src._data, _size);
}

String::~String()
{
	delete[] _data;
}

void String::resize(int new_size)
{
	char* tmp_data = new char[new_size];
	memcpy_s(tmp_data, new_size, _data, (_size < new_size ? _size : new_size));
	delete[] _data;
	if (new_size < _size)
		tmp_data[new_size - 1] = 0;
	_data = tmp_data;
	_size = new_size;
}

int String::size() const
{
	return _size;
}

int String::length() const
{
	return strlen(_data);
}

const char* String::str() const
{
	return (const char*)_data;
}

int String::find(char ch) const
{
	for (int i = 0; i < length(); ++i)
		if (_data[i] == ch)
			return i;
	return -1;
}

char& String::operator[](int idx) const
{
	if (idx >= strlen(_data))
		throw "Error: invalid idx";
	return _data[idx];
}

String& String::operator=(const String& right)
{
	if (this != &right)
	{
		_size = right._size;
		delete[] _data;
		_data = new char[_size];
		memcpy_s(_data, _size, right._data, right._size);
	}
	return *this;
}

String& String::operator+=(const String& right)
{
	if (right._data == nullptr)
		return *this;
	if (length() + right.length() + 1 > size())
		resize(length() + right.length() + 1);
	if (this == &right)
	{
		int beg_length = length();
		for (int i = 0; i < beg_length; ++i)
			_data[i + beg_length] = _data[i];
		_data[2 * beg_length] = 0;
	}
	else
		memcpy_s(_data + length(), _size - length(), right._data, right.length() + 1);
	return *this;
}
String String::operator+(const String& right) const
{
	String sum(length() + right.length() + 1);
	memcpy_s(sum._data, sum._size, _data, length());
	memcpy_s(sum._data + length(), sum._size - length(), right._data, right.length() + 1);
	return sum;
}

bool String::operator==(const String& right) const
{
	if (_size != right._size)
		return false;
	if (this == &right)
		return true;
	for (int i = 0; i < _size; ++i)
		if (_data[i] != right._data[i])
			return false;
	return true;
}
bool String::operator!=(const String& right) const
{
	return !(*this == right);
}
bool String::operator<(const String& right) const
{
	int min_size = _size < right._size ? _size : right._size;
	for (int i = 0; i < min_size; ++i)
	{
		if (_data[i] < right._data[i])
			return true;
		else if (_data[i] > right._data[i])
			return false;
	}
	if (_size < right._size)
		return true;
	else
		return false;
}

bool String::operator<=(const String& right) const { return (*this == right) || (*this < right); }
bool String::operator>(const String& right) const { return !(*this <= right); }
bool String::operator>=(const String& right) const { return !(*this < right); }

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.str();
	return stream;
}

std::istream& operator>>(std::istream& stream, String& str)
{
	char src[257];
	stream >> src;
	str = String(src);
	str.resize(str.length() + 1);
	return stream;
}