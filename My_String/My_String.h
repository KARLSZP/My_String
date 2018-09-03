#pragma once
#include<iostream>
#include<cstring>
#include"My_String.h"
//#include<string>
using namespace std;

struct My_String_Data
{
	char* _data;
	size_t length;
	size_t capacity;
};

class My_String {
public:
	//constructors
	My_String();
	My_String(const My_String&);
	My_String(const My_String&, size_t, size_t);
	My_String(const char*);
	My_String(const char*, size_t);
	My_String(size_t, char);

	//destructor
	~My_String();

	//operator=
	My_String& operator=(const My_String&);
	My_String& operator=(const char*);
	My_String& operator=(const char);

	//size & capacity
	size_t size() const;
	size_t length() const;
	size_t capacity() const;
	bool empty() const;
	void resize(size_t);
	void reserve(size_t);
	void clear();

	//access to elements
	char& operator[](size_t);
	const char& operator[](size_t) const;
	char& at(size_t);
	const char& at(size_t) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	char* c_str();
	const char* c_str() const;
	const My_String_Data* get_data() const;

	//modifiers
	My_String& operator+=(const My_String&);
	My_String& operator+=(const char*);
	My_String& operator+=(const char);
	void append(const My_String&);
	void append(const My_String&, size_t, size_t);
	void append(const char*);
	void append(const char*, size_t);
	void append(size_t, char);
	void push_back(const char);
	void assign(const My_String&);
	void assign(const My_String&, size_t, size_t);
	void assign(const char*);
	void assign(const char*, size_t);
	void assign(size_t, char);
	void insert(size_t, My_String&, size_t, size_t);
	void insert(size_t, const char*, size_t);
	void insert(size_t, size_t, char);
	void erase(size_t, size_t);
	void replace(size_t, size_t, const My_String&, size_t, size_t);
	void replace(size_t, size_t, const char*, size_t);
	void replace(size_t, size_t, size_t, const char);
	void swap(My_String&);
	void pop_back();

	//string operations

private:
	My_String_Data * data;
};
