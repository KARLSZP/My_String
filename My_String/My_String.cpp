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

char* My_String::c_str() {
	return data->_data;
}

const char* My_String::c_str() const {
	return data->_data;
}

const My_String_Data* My_String::get_data() const {
	return data;
}

#endif // !My_String_H