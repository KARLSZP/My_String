#pragma once
#include<iostream>
#include<cstring>
#include"My_String.h"
//#include<string>
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
	const char* c_str() const;
	const char* data() const;
	size_t copy(char*, size_t, size_t);

	size_t find(const string& str, size_t pos = 0) const noexcept;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const noexcept;

	size_t rfind(const string& str, size_t pos = 0) const noexcept;
	size_t rfind(const char* s, size_t pos = 0) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = 0) const noexcept;

	size_t find_first_of(const string& str, size_t pos = 0) const noexcept;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const noexcept;

	size_t find_last_of(const string& str, size_t pos = npos) const noexcept;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const noexcept;

	size_t find_first_not_of(const string& str, size_t pos = 0) const noexcept;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const noexcept;

	size_t find_last_not_of(const string& str, size_t pos = npos) const noexcept;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const noexcept;

	My_String substr(size_t pos = 0, size_t len = npos) const;

	int compare(const string& str) const noexcept;
	int compare(size_t pos, size_t len, const string& str) const;
	int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	//friend Non-member function overloads
	friend istream& getline(istream&  is, string& str, char delim);
	friend istream& getline(istream&& is, string& str, char delim);
	friend istream& getline(istream&  is, string& str);
	friend istream& getline(istream&& is, string& str);

	friend string operator+ (const string& lhs, const string& rhs);
	friend string operator+ (string&&      lhs, string&&      rhs);
	friend string operator+ (string&&      lhs, const string& rhs);
	friend string operator+ (const string& lhs, string&&      rhs);
	friend string operator+ (const string& lhs, const char*   rhs);
	friend string operator+ (string&&      lhs, const char*   rhs);
	friend string operator+ (const char*   lhs, const string& rhs);
	friend string operator+ (const char*   lhs, string&&      rhs);
	friend string operator+ (const string& lhs, char          rhs);
	friend string operator+ (string&&      lhs, char          rhs);
	friend string operator+ (char          lhs, const string& rhs);
	friend string operator+ (char          lhs, string&&      rhs);

	friend istream& operator>> (istream& is, string& str);
	friend ostream& operator<< (ostream& os, const string& str);
	friend void swap(string& x, string& y);

	friend bool operator==(const string& lhs, const string& rhs);
	friend bool operator==(const char*   lhs, const string& rhs);
	friend bool operator==(const string& lhs, const char*   rhs);
	friend bool operator!=(const string& lhs, const string& rhs);
	friend bool operator!=(const char*   lhs, const string& rhs);
	friend bool operator!=(const string& lhs, const char*   rhs);
	friend bool operator< (const string& lhs, const string& rhs);
	friend bool operator< (const char*   lhs, const string& rhs);
	friend bool operator< (const string& lhs, const char*   rhs);
	friend bool operator<=(const string& lhs, const string& rhs);
	friend bool operator<=(const char*   lhs, const string& rhs);
	friend bool operator<=(const string& lhs, const char*   rhs);
	friend bool operator> (const string& lhs, const string& rhs);
	friend bool operator> (const char*   lhs, const string& rhs);
	friend bool operator> (const string& lhs, const char*   rhs);
	friend bool operator>=(const string& lhs, const string& rhs);
	friend bool operator>=(const char*   lhs, const string& rhs);
	friend bool operator>=(const string& lhs, const char*   rhs);

private:
	My_String_Data * data;
};
