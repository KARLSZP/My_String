#ifndef My_String_H
#define My_String_H

#include"My_String.h"

//constructors
My_String::My_String() {
	data->_data = new char[1];
	data->capacity = 1;
	data->length = 0;
	data->_data = '\0';
}

My_String::My_String(const My_String& str) {
	data->_data = new char[str.get_data()->capacity];
	data->capacity = str.get_data()->capacity;
	data->length = str.get_data()->length;
	strcpy(data->_data, str.get_data()->_data);
}

My_String::My_String(const My_String& str, size_t pos, size_t num) {
	data->_data = new char[num + 1];
	data->capacity = str.get_data()->capacity;
	data->length = num;
	for (int i = pos; i < str.get_data()->length; i++) {
		data->_data[i - pos] = str.get_data()->_data[i];
	}
	data->_data[num] = '\0';
}

My_String::My_String(const char* str) {
	size_t len = strlen(str);
	data->_data = new char[len + 1];
	data->capacity = len + 1;
	data->length = len;
	strcpy(data->_data, str);
}
My_String::My_String(const char* str, size_t num) {
	data->_data = new char[num + 1];
	data->capacity = num + 1;
	data->length = num;
	strncpy(data->_data, str, num);
}
My_String::My_String(size_t num, char chr) {
	data->_data = new char[num + 1];
	data->capacity = num + 1;
	data->length = num;
	for (size_t i = 0; i < num; i++) {
		data->_data[i] = chr;
	}
	data->_data[num] = '\0';
}

//destructor
My_String::~My_String() {
	delete[] data->_data;
}

//operator=
My_String& My_String::operator=(const My_String& str) {
	delete[] data->_data;
	data->_data = new char[str.get_data()->capacity];
	data->capacity = str.get_data()->capacity;
	data->length = str.get_data()->length;
	strcpy(data->_data, str.get_data()->_data);
	return *this;
}

My_String& My_String::operator=(const char* str) {
	delete[] data->_data;
	size_t len = strlen(str);
	data->_data = new char[len + 1];
	data->capacity = len + 1;
	data->length = len;
	strcpy(data->_data, str);
	return *this;
}

My_String& My_String::operator=(const char chr) {
	delete[] data->_data;
	data->_data = new char[2];
	data->capacity = 2;
	data->length = 1;
	data->_data[0] = chr;
	data->_data[1] = '\0';
	return *this;
}

//size & capacity
size_t My_String::size() const {
	return data->length;
}

size_t My_String::length() const {
	return data->length;
}


size_t My_String::capacity() const {
	return data->capacity;
}

bool My_String::empty() const {
	return data->length ? true : false;
}

void My_String::resize(size_t num) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	if (num >= data->capacity) {
		data->_data = new char[num];
		strcpy(data->_data, buf);
	}
	else {
		data->_data = new char[num];
		strncpy(data->_data, buf, num - 1);
	}
	data->capacity = num;
	delete[] buf;
}

void My_String::reserve(size_t num) {
	if (num >= data->capacity) {
		this->resize(num);
	}
	else {
		this->resize(data->length);
	}
}

void My_String::clear() {
	delete[] data->_data;
	data->_data = new char[1];
	data->capacity = 1;
	data->length = 0;
	data->_data = '\0';
}

//access to elements
char& My_String::operator[](size_t pos) {
	return data->_data[pos];
}

const char& My_String::operator[](size_t pos) const {
	return data->_data[pos];
}

char& My_String::at(size_t pos) {
	if (pos >= data->length) {
		throw(out_of_range("Invalid Position!"));
	}
	else {
		return data->_data[pos];
	}
	/*try {

	}
	catch (out_of_range & e) {
	cout << e.what() << endl;
	}*/
}

const char& My_String::at(size_t pos) const {
	if (pos >= data->length) {
		throw(out_of_range("Invalid Position!"));
	}
	else {
		return data->_data[pos];
	}
	/*try {

	}
	catch (out_of_range & e) {
	cout << e.what() << endl;
	}*/
}

char& My_String::front() {
	return data->_data[0];
}

const char& My_String::front() const {
	return data->_data[0];
}

char& My_String::back() {
	return data->_data[data->length - 1];
}

const char& My_String::back() const {
	return data->_data[data->length - 1];
}


const char* My_String::c_str() const {
	return data->_data;
}

const My_String_Data* My_String::get_data() const {
	return data;
}

//modifiers
My_String& My_String::operator+=(const My_String& str) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + str.get_data()->capacity];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < str.get_data()->length; i++) {
		data->_data[data->length + i] = str.get_data()->_data[i];
	}
	data->_data[data->length + str.get_data()->length] = '\0';
	data->capacity = data->capacity + str.get_data()->capacity;
	data->length = data->length + str.get_data()->length;
	delete[] buf;
	return *this;
}

My_String& My_String::operator+=(const char* str) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + strlen(str)];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < strlen(str); i++) {
		data->_data[data->length + i] = str[i];
	}
	data->_data[data->length + strlen(str)] = '\0';
	data->capacity = data->capacity + strlen(str);
	data->length = data->length + strlen(str);
	delete[] buf;
	return *this;
}

My_String& My_String::operator+=(const char chr) {
	if (data->capacity > data->length + 1) {
		data->_data[data->length] = chr;
		data->_data[data->length + 1] = '\0';
	}
	else {
		char* buf = new char[data->capacity];
		strcpy(buf, data->_data);
		delete[] data->_data;
		data->_data = new char[data->length + 1];
		strcpy(data->_data, buf);
		data->_data[data->length] = chr;
		data->_data[data->length + 1] = '\0';
		data->capacity = data->length + 1;
		data->length = data->length + 1;
		delete[] buf;		
	}
	return *this;
}

void My_String::append(const My_String& str) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + str.get_data()->capacity];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < str.get_data()->length; i++) {
		data->_data[data->length + i] = str.get_data()->_data[i];
	}
	data->_data[data->length + str.get_data()->length] = '\0';
	data->capacity = data->capacity + str.get_data()->capacity;
	data->length = data->length + str.get_data()->length;
	delete[] buf;
}

void My_String::append(const My_String& str, size_t pos, size_t num) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + num];
	strcpy(data->_data, buf);
	for (size_t i = pos; i < pos + num; i++) {
		data->_data[data->length + i - pos] = str.get_data()->_data[i];
	}
	data->_data[data->length + num] = '\0';
	data->capacity = data->capacity + num;
	data->length = data->length + num;
	delete[] buf;
}

void My_String::append(const char* str) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + strlen(str)];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < strlen(str); i++) {
		data->_data[data->length + i] = str[i];
	}
	data->_data[data->length + strlen(str)] = '\0';
	data->capacity = data->capacity + strlen(str);
	data->length = data->length + strlen(str);
	delete[] buf;
}

void My_String::append(const char* str, size_t num) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + num];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < num; i++) {
		data->_data[data->length + i] = str[i];
	}
	data->_data[data->length + num] = '\0';
	data->capacity = data->capacity + num;
	data->length = data->length + num;
	delete[] buf;
}

void My_String::append(size_t num, char chr) {
	char* buf = new char[data->capacity];
	strcpy(buf, data->_data);
	delete[] data->_data;
	data->_data = new char[data->capacity + num];
	strcpy(data->_data, buf);
	for (size_t i = 0; i < num; i++) {
		data->_data[data->length + i] = chr;
	}
	data->_data[data->length + num] = '\0';
	data->capacity = data->capacity + num;
	data->length = data->length + num;
	delete[] buf;
}

void My_String::push_back(const char chr) {
	this->append(1, chr);
}

void My_String::assign(const My_String&);
void My_String::assign(const My_String&, size_t, size_t);
void My_String::assign(const char*);
void My_String::assign(const char*, size_t);
void My_String::assign(size_t, char);
void My_String::insert(size_t, My_String&, size_t, size_t);
void My_String::insert(size_t, const char*, size_t);
void My_String::insert(size_t, size_t, char);
void My_String::erase(size_t, size_t);
void My_String::replace(size_t, size_t, const My_String&, size_t, size_t);
void My_String::replace(size_t, size_t, const char*, size_t);
void My_String::replace(size_t, size_t, size_t, const char);
void My_String::swap(My_String&);
void My_String::pop_back();

//string operations
const My_String::char* c_str() const;
const My_String::char* data() const;
size_t My_String::copy(char*, size_t, size_t);

size_t My_String::find(const string& str, size_t pos = 0) const noexcept;
size_t My_String::find(const char* s, size_t pos = 0) const;
size_t My_String::find(const char* s, size_t pos, size_t n) const;
size_t My_String::find(char c, size_t pos = 0) const noexcept;

size_t My_String::rfind(const string& str, size_t pos = 0) const noexcept;
size_t My_String::rfind(const char* s, size_t pos = 0) const;
size_t My_String::rfind(const char* s, size_t pos, size_t n) const;
size_t My_String::rfind(char c, size_t pos = 0) const noexcept;

size_t My_String::find_first_of(const string& str, size_t pos = 0) const noexcept;
size_t My_String::find_first_of(const char* s, size_t pos = 0) const;
size_t My_String::find_first_of(const char* s, size_t pos, size_t n) const;
size_t My_String::find_first_of(char c, size_t pos = 0) const noexcept;

size_t My_String::find_last_of(const string& str, size_t pos = npos) const noexcept;
size_t My_String::find_last_of(const char* s, size_t pos = npos) const;
size_t My_String::find_last_of(const char* s, size_t pos, size_t n) const;
size_t My_String::find_last_of(char c, size_t pos = npos) const noexcept;

size_t My_String::find_first_not_of(const string& str, size_t pos = 0) const noexcept;
size_t My_String::find_first_not_of(const char* s, size_t pos = 0) const;
size_t My_String::find_first_not_of(const char* s, size_t pos, size_t n) const;
size_t My_String::find_first_not_of(char c, size_t pos = 0) const noexcept;

size_t My_String::find_last_not_of(const string& str, size_t pos = npos) const noexcept;
size_t My_String::find_last_not_of(const char* s, size_t pos = npos) const;
size_t My_String::find_last_not_of(const char* s, size_t pos, size_t n) const;
size_t My_String::find_last_not_of(char c, size_t pos = npos) const noexcept;

My_String My_String::substr(size_t pos = 0, size_t len = npos) const;

int My_String::compare(const string& str) const noexcept;
int My_String::compare(size_t pos, size_t len, const string& str) const;
int My_String::compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
int My_String::compare(const char* s) const;
int My_String::compare(size_t pos, size_t len, const char* s) const;
int My_String::compare(size_t pos, size_t len, const char* s, size_t n) const;

//friend Non-member function overloads
istream& getline(istream&  is, string& str, char delim);
istream& getline(istream&& is, string& str, char delim);
istream& getline(istream&  is, string& str);
istream& getline(istream&& is, string& str);

string operator+ (const string& lhs, const string& rhs);
string operator+ (string&&      lhs, string&&      rhs);
string operator+ (string&&      lhs, const string& rhs);
string operator+ (const string& lhs, string&&      rhs);
string operator+ (const string& lhs, const char*   rhs);
string operator+ (string&&      lhs, const char*   rhs);
string operator+ (const char*   lhs, const string& rhs);
string operator+ (const char*   lhs, string&&      rhs);
string operator+ (const string& lhs, char          rhs);
string operator+ (string&&      lhs, char          rhs);
string operator+ (char          lhs, const string& rhs);
string operator+ (char          lhs, string&&      rhs);

istream& operator>> (istream& is, string& str);
ostream& operator<< (ostream& os, const string& str);
void swap(string& x, string& y);

bool operator==(const string& lhs, const string& rhs);
bool operator==(const char*   lhs, const string& rhs);
bool operator==(const string& lhs, const char*   rhs);
bool operator!=(const string& lhs, const string& rhs);
bool operator!=(const char*   lhs, const string& rhs);
bool operator!=(const string& lhs, const char*   rhs);
bool operator< (const string& lhs, const string& rhs);
bool operator< (const char*   lhs, const string& rhs);
bool operator< (const string& lhs, const char*   rhs);
bool operator<=(const string& lhs, const string& rhs);
bool operator<=(const char*   lhs, const string& rhs);
bool operator<=(const string& lhs, const char*   rhs);
bool operator> (const string& lhs, const string& rhs);
bool operator> (const char*   lhs, const string& rhs);
bool operator> (const string& lhs, const char*   rhs);
bool operator>=(const string& lhs, const string& rhs);
bool operator>=(const char*   lhs, const string& rhs);
bool operator>=(const string& lhs, const char*   rhs);
#endif // !My_String_H