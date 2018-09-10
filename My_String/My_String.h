#pragma once
#include<iostream>
#include<cstring>
#include"My_String.h"
//#include<My_String>
using namespace std;

static const size_t npos = -1;

struct My_String_Data
{
	char* _data;
	size_t length;
	size_t capacity;
};

class My_String {
public:
	//constructors
	My_String();//¡Ì
	My_String(const My_String&);//¡Ì
	My_String(const My_String&, size_t, size_t num= npos);//¡Ì
	My_String(const char*);//¡Ì
	My_String(const char*, size_t);//¡Ì
	My_String(size_t, char);//¡Ì

	//destructor
	~My_String();//¡Ì

	//operator=
	My_String& operator=(const My_String&);//¡Ì
	My_String& operator=(const char*);//¡Ì
	My_String& operator=(const char);//¡Ì

	//size & capacity
	size_t size() const;//¡Ì
	size_t length() const;//¡Ì
	size_t capacity() const;//¡Ì
	bool empty() const;//¡Ì
	void resize(size_t);//¡Ì
	void reserve(size_t);//¡Ì
	void clear();//¡Ì

	//access to elements
	char& operator[](size_t);//¡Ì
	const char& operator[](size_t) const;//¡Ì
	char& at(size_t);//¡Ì
	const char& at(size_t) const;//¡Ì
	char& front();//¡Ì
	const char& front() const;//¡Ì
	char& back();//¡Ì
	const char& back() const;//¡Ì
	const My_String_Data* get_data() const;//¡Ì

	//modifiers
	My_String& operator+=(const My_String&);//¡Ì
	My_String& operator+=(const char*);//¡Ì
	My_String& operator+=(const char);//¡Ì

	void append(const My_String&);//¡Ì
	void append(const My_String&, size_t, size_t num = npos);//¡Ì
	void append(const char*);//¡Ì
	void append(const char*, size_t);//¡Ì
	void append(size_t, char);//¡Ì

	void push_back(const char);//¡Ì

	void assign(const My_String&);//¡Ì
	void assign(const My_String&, size_t, size_t num = npos);//¡Ì
	void assign(const char*);//¡Ì
	void assign(const char*, size_t);//¡Ì
	void assign(size_t, char);//¡Ì

	My_String& insert(size_t, My_String&);//¡Ì
	My_String& insert(size_t, My_String&, size_t, size_t sublen = npos);//¡Ì
	My_String& insert(size_t, const char*);//¡Ì
	My_String& insert(size_t, const char*, size_t);//¡Ì
	My_String& insert(size_t, size_t, char);//¡Ì

	My_String& erase(size_t, size_t);//¡Ì

	My_String& replace(size_t, size_t, const My_String&);//¡Ì
	My_String& replace(size_t, size_t, const My_String&, size_t, size_t sublen = npos);//¡Ì
	My_String& replace(size_t, size_t, const char*);//¡Ì
	My_String& replace(size_t, size_t, const char*, size_t);//¡Ì
	My_String& replace(size_t, size_t, size_t, const char);//¡Ì

	void swap(My_String&);//¡Ì
	char pop_back();//¡Ì

	//My_String operations
	const char* c_str() const;//¡Ì
	size_t copy(char*, size_t, size_t);

	size_t to_find(const char*,const char*, size_t) const;
	size_t find(const My_String& str, size_t pos) const noexcept;
	size_t find(const char* s, size_t pos) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos) const noexcept;

	size_t to_rfind(const char*, const char*, size_t) const;
	size_t rfind(const My_String& str, size_t pos) const noexcept;
	size_t rfind(const char* s, size_t pos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos) const noexcept;

	size_t to_find_first(const char*, const char*, size_t) const;
	size_t find_first_of(const My_String& str, size_t pos) const noexcept;
	size_t find_first_of(const char* s, size_t pos) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos) const noexcept;

	size_t to_find_last(const char*, const char*, size_t) const;
	size_t find_last_of(const My_String& str, size_t pos) const noexcept;
	size_t find_last_of(const char* s, size_t pos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos) const noexcept;

	size_t to_find_first_not(const char*, const char*, size_t) const;
	size_t find_first_not_of(const My_String& str, size_t pos) const noexcept;
	size_t find_first_not_of(const char* s, size_t pos) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos) const noexcept;

	size_t to_find_last_not(const char*, const char*, size_t) const;
	size_t find_last_not_of(const My_String& str, size_t pos) const noexcept;
	size_t find_last_not_of(const char* s, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos) const noexcept;

	My_String substr(size_t pos, size_t len) const;

	int compare(const My_String& str) const noexcept;
	int compare(size_t pos, size_t len, const My_String& str) const;
	int compare(size_t pos, size_t len, const My_String& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	//friend Non-member function overloads
	friend istream& operator>> (istream& is, My_String& str);
	friend ostream& operator<< (ostream& os, const My_String& str);
	friend istream& getline(istream& is, My_String& str, char delim);
	friend istream& getline(istream& is, My_String& str);

	friend My_String operator+ (const My_String& lhs, const My_String& rhs);
	friend My_String operator+ (const My_String& lhs, const char* rhs);
	friend My_String operator+ (const char* lhs, const My_String& rhs);
	friend My_String operator+ (const My_String& lhs, char rhs);
	friend My_String operator+ (char lhs, const My_String& rhs);

	friend void swap(My_String& x, My_String& y);

	friend bool operator==(const My_String& lhs, const My_String& rhs);
	friend bool operator==(const char* lhs, const My_String& rhs);
	friend bool operator==(const My_String& lhs, const char* rhs);
	friend bool operator!=(const My_String& lhs, const My_String& rhs);
	friend bool operator!=(const char* lhs, const My_String& rhs);
	friend bool operator!=(const My_String& lhs, const char* rhs);
	friend bool operator< (const My_String& lhs, const My_String& rhs);
	friend bool operator< (const char* lhs, const My_String& rhs);
	friend bool operator< (const My_String& lhs, const char* rhs);
	friend bool operator<=(const My_String& lhs, const My_String& rhs);
	friend bool operator<=(const char* lhs, const My_String& rhs);
	friend bool operator<=(const My_String& lhs, const char* rhs);
	friend bool operator> (const My_String& lhs, const My_String& rhs);
	friend bool operator> (const char* lhs, const My_String& rhs);
	friend bool operator> (const My_String& lhs, const char* rhs);
	friend bool operator>=(const My_String& lhs, const My_String& rhs);
	friend bool operator>=(const char* lhs, const My_String& rhs);
	friend bool operator>=(const My_String& lhs, const char* rhs);

private:
	My_String_Data* data;
};

//POS out of bound