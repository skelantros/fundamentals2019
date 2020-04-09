#pragma once

class String
{
private:
	size_t _size;
	char* _data;
public:
	void resize(int new_size);
public:
	String(const char* str = "");
	String(int size);
	String(const String&);
	~String();

	int size() const;
	int length() const;
	const char* str() const;

	int find(char ch) const;

	char& operator[](int idx) const;
	String& operator= (const String&);
	String& operator+=(const String&);
	String  operator+ (const String&) const;

	bool operator==(const String& X) const;
	bool operator!=(const String& X) const;
	bool operator< (const String& X) const;
	bool operator<=(const String& X) const;
	bool operator> (const String& X) const;
	bool operator>=(const String& X) const;
};

#include <iostream>
std::ostream& operator<< (std::ostream&, const String&);
std::istream& operator>> (std::istream&, String&);