#define _CRT_SECURE_NO_WARNINGS
#ifndef My_String_H
#define My_String_H

#include"My_String.h"

//constructors
My_String::My_String() {
	data = new My_String_Data;
	data->_data = new char[1];
	data->capacity = 1;
	data->length = 0;
	data->_data[0] = '\0';
}

My_String::My_String(const My_String& str) {
	data = new My_String_Data;
	data->_data = new char[str.get_data()->capacity];
	data->capacity = str.get_data()->capacity;
	data->length = str.get_data()->length;
	strcpy(data->_data, str.get_data()->_data);
	//assign(str);
}

My_String::My_String(const My_String& str, size_t pos, size_t num) {
	data = new My_String_Data;
	data->capacity = 1;
	data->length = 0;
	data->_data = new char[1];
	assign(str, pos, num);
}

My_String::My_String(const char* str) {
	data = new My_String_Data;
	size_t len = strlen(str);
	data->_data = new char[len + 1];
	data->capacity = len + 1;
	data->length = len;
	strcpy(data->_data, str);
}
My_String::My_String(const char* str, size_t num) {
	data = new My_String_Data;
	data->_data = new char[num + 1];
	data->capacity = num + 1;
	data->length = num;
	strncpy(data->_data, str, num);
	data->_data[data->length] = '\0';
}
My_String::My_String(size_t num, char chr) {
	if (num < 0) {
		throw(out_of_range("Invalid Position!"));
	}
	data = new My_String_Data;
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
	delete data;
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
		data->_data[num] = '\0';
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
	if (pos >= data->length || pos < 0) {
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
		append(1, chr);
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
	My_String app(str, pos, num);
	append(app);
	/*char* buf = new char[data->capacity];
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
	delete[] buf;*/
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

void My_String::assign(const My_String& str) {
	delete[] data->_data;
	data->_data = new char[str.get_data()->capacity];
	data->capacity = str.get_data()->capacity;
	data->length = str.get_data()->length;
	strcpy(data->_data, str.get_data()->_data);
}

void My_String::assign(const My_String& str, size_t pos, size_t num) {
	if (pos > str.data->length || num < 0 || pos < 0) {
		throw(out_of_range("Invalid Position!"));
	}
	delete[] data->_data;
	const char* ptr = str.c_str() + pos;
	data->length = strlen(ptr) > num ? num : strlen(ptr);
	data->capacity = data->length + 1;
	data->_data = new char[data->capacity];
	for (size_t i = 0; i < data->length; i++) {
		data->_data[i] = str.get_data()->_data[i + pos];
	}
	data->_data[data->length] = '\0';
}

void My_String::assign(const char* str) {
	delete[] data->_data;
	data->_data = new char[strlen(str) + 1];
	data->capacity = strlen(str) + 1;
	data->length = strlen(str);
	strcpy(data->_data, str);
}

void My_String::assign(const char* str, size_t num) {
	delete[] data->_data;
	data->_data = new char[num + 1];
	data->capacity = num + 1;
	data->length = num;
	for (size_t i = 0; i < num; i++) {
		data->_data[i] = str[i];
	}
	data->_data[num] = '\0';
}

void My_String::assign(size_t num, char chr) {
	delete[] data->_data;
	data->_data = new char[num + 1];
	data->capacity = num + 1;
	data->length = num;
	for (size_t i = 0; i < num; i++) {
		data->_data[i] = chr;
	}
	data->_data[num] = '\0';
}

My_String& My_String::insert(size_t pos, My_String& str) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos);
	str_f += str;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::insert(size_t pos_ins, My_String& str, size_t pos, size_t num) {
	My_String str_f(*this, 0, pos_ins);
	My_String str_b(*this, pos_ins);
	My_String str_ins(str, pos, num);
	str_f += str_ins;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::insert(size_t pos, const char* str) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos);
	str_f += str;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::insert(size_t pos_ins, const char* str, size_t num) {
	My_String str_f(*this, 0, pos_ins);
	My_String str_b(*this, pos_ins);
	My_String str_ins(str, num);
	str_f += str_ins;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::insert(size_t pos, size_t num, char chr) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos);
	for (size_t i = 0; i < num; i++) {
		str_f += chr;
	}
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::erase(size_t pos = 0, size_t num = npos) {
	//size_t erase_len = data->length > num ? num - pos : data->length - pos;
	My_String str_f(*this, 0, pos);
	if (num < data->length) {
		My_String str_b(*this, pos + num);
		str_f += str_b;
	}
	assign(str_f);
	return *this;
}

My_String& My_String::replace(size_t pos, size_t len, const My_String& str) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos + len);
	str_f += str;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::replace(size_t pos, size_t len, const My_String& str, size_t subpos, size_t sublen) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos + len);
	My_String str_rep(str, subpos, sublen);
	str_f += str_rep;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::replace(size_t pos, size_t len, const char* str) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos + len);
	str_f += str;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::replace(size_t pos, size_t len, const char* str, size_t num) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos + len);
	My_String str_rep(str, num);
	str_f += str_rep;
	str_f += str_b;
	assign(str_f);
	return *this;
}

My_String& My_String::replace(size_t pos, size_t len, size_t num, const char chr) {
	My_String str_f(*this, 0, pos);
	My_String str_b(*this, pos + len);
	My_String str_rep(num, chr);
	str_f += str_rep;
	str_f += str_b;
	assign(str_f);
	return *this;
}

void My_String::swap(My_String& str) {
	My_String tmp(*this);
	assign(str);
	str = tmp;
}

char My_String::pop_back() {
	if (data->length > 0) {
		data->length--;
	}
	else {
		return '\0';
	}
	char tmp = data->_data[data->length];
	data->_data[data->length] = '\0';
	return tmp;
}

//string operations
const char* My_String::c_str() const {
	return data->_data;
}

size_t My_String::copy(char* buf, size_t len, size_t pos = 0) {
	if (pos > data->length || pos < 0) {
		throw(out_of_range("Invalid Position!"));
	}
	else {
		size_t l = len > data->length - pos ? len : data->length - pos;
		My_String tmp(*this, pos, len);
		strcpy(buf, tmp.c_str());
	}
	return len > data->length - pos ? data->length - pos : len;
}

size_t My_String::to_find(const char* s1,const char* s2, size_t pos) const {
	int i = pos, j = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	while (i < len1&&j < len2) {
		if (*(s1 + i) == *(s2 + j)) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	return j >= len2 ? i - len2 : npos;
}

size_t My_String::find(const My_String& str, size_t pos) const noexcept {
	return to_find(data->_data, str.get_data()->_data, pos);
}

size_t My_String::find(const char* s, size_t pos) const {
	return to_find(data->_data, s, pos);
}

size_t My_String::find(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_find(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::find(char c, size_t pos) const noexcept {
	char s[2];
	s[0] = c;
	s[1] = '\0';
	return to_find(data->_data, s, pos);
}

size_t My_String::to_rfind(const char * s1, const char* s2, size_t pos) const {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = pos == npos ? len1 : pos, j = len2, k = 1;
	while (i >= 0&&j > 0) {
		if (*(s1 + i) == *(s2 + j - 1)) {
			i--;
			j--;
		}
		else {
			i = pos - k;
			j = len2;
			k++;
		}
	}
	return j ? npos : i + 1;
}
size_t My_String::rfind(const My_String& str, size_t pos) const noexcept {
	return to_rfind(data->_data, str.get_data()->_data, pos);
}

size_t My_String::rfind(const char* s, size_t pos) const {
	return to_rfind(data->_data, s, pos);
}

size_t My_String::rfind(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_rfind(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::rfind(char c, size_t pos) const noexcept {
	char s[1];
	s[0] = c;
	return to_rfind(data->_data, s, pos);
}

size_t My_String::to_find_first(const char * s1, const char* s2, size_t pos) const {
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	size_t i = pos, j = 0;
	for (; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (*(s1 + i) == *(s2 + j)) {
				return i;
			}
		}
	}
	return npos;
}

size_t My_String::find_first_of(const My_String& str, size_t pos) const noexcept {
	return to_find_first(data->_data, str.get_data()->_data, pos);
}

size_t My_String::find_first_of(const char* s, size_t pos) const {
	return to_find_first(data->_data, s, pos);
}

size_t My_String::find_first_of(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_find_first(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::find_first_of(char c, size_t pos) const noexcept {
	char s[1];
	s[0] = c;
	return to_find_first(data->_data, s, pos);
}

size_t My_String::to_find_last(const char* s1, const char* s2, size_t pos) const {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = pos > len1 ? len1 - 1 : pos , j = 0, res = npos;
	for (; i >= 0; i--) {
		for (j = 0; j < len2; j++) {
			if (*(s1 + i) == *(s2 + j)) {
				break;
			}
		}
		if (j < len2) res = i;
	}
	return res;
}

size_t My_String::find_last_of(const My_String& str, size_t pos) const noexcept {
	return to_find_last(data->_data, str.get_data()->_data, pos);
}

size_t My_String::find_last_of(const char* s, size_t pos) const {
	return to_find_last(data->_data, s, pos);
}

size_t My_String::find_last_of(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_find_last(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::find_last_of(char c, size_t pos) const noexcept {
	char s[1];
	s[0] = c;
	return to_find_last(data->_data, s, pos);
}

size_t My_String::to_find_first_not(const char* s1, const char* s2, size_t pos) const {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = pos, j = 0;
	for (; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (*(s1 + i) == *(s2 + j)) {
				break;
			}
		}
		if (j >= len2) return i;
	}
	return npos;
}

size_t My_String::find_first_not_of(const My_String& str, size_t pos) const noexcept {
	return to_find_first_not(data->_data, str.get_data()->_data, pos);
}

size_t My_String::find_first_not_of(const char* s, size_t pos) const {
	return to_find_first_not(data->_data, s, pos);
}

size_t My_String::find_first_not_of(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_find_first_not(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::find_first_not_of(char c, size_t pos) const noexcept {
	char s[1];
	s[0] = c;
	return to_find_first_not(data->_data, s, pos);
}

size_t My_String::to_find_last_not(const char* s1, const char* s2, size_t pos) const {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = pos > len1 ? len1 - 1 : pos , j = 0, res = npos;
	for (; i >=0; i--) {
		for (j = 0; j < len2; j++) {
			if (*(s1 + i) == *(s2 + j)) {
				break;
			}
		}
		if (j >= len2) return i;
	}
	return res;
}
size_t My_String::find_last_not_of(const My_String& str, size_t pos) const noexcept {
	return to_find_last_not(data->_data, str.get_data()->_data, pos);
}

size_t My_String::find_last_not_of(const char* s, size_t pos) const {
	return to_find_last_not(data->_data, s, pos);
}

size_t My_String::find_last_not_of(const char* s, size_t pos, size_t n) const {
	My_String tmp(s, n);
	return to_find_last_not(data->_data, tmp.get_data()->_data, pos);
}

size_t My_String::find_last_not_of(char c, size_t pos) const noexcept {
	char s[1];
	s[0] = c;
	return to_find_last_not(data->_data, s, pos);
}

My_String My_String::substr(size_t pos = 0, size_t len = npos) const {
	My_String substring(*this, pos, len);
	return substring;
}

int My_String::compare(const My_String& str) const noexcept {
	return strcmp(data->_data, str.c_str());
}

int My_String::compare(size_t pos, size_t len, const My_String& str) const {
	My_String tmp(data->_data, pos, len);
	return tmp.compare(str);
}

int My_String::compare(size_t pos, size_t len, const My_String& str, size_t subpos, size_t sublen) const {
	My_String tmp1(data->_data, pos, len);
	My_String tmp2(str.c_str(), subpos, sublen);
	return tmp1.compare(tmp2);
}

int My_String::compare(const char* s) const {
	return strcmp(data->_data, s);
}

int My_String::compare(size_t pos, size_t len, const char* s) const {
	My_String tmp(data->_data, pos, len);
	return tmp.compare(s);
}

int My_String::compare(size_t pos, size_t len, const char* s, size_t n) const {
	My_String tmp1(data->_data, pos, len);
	My_String tmp2(s, n);
	return tmp1.compare(tmp2);
}

//friend Non-member function overloads
istream& operator>> (istream& is, My_String& str) {
	str.erase();
	char ch;
	is >> ch;
	while (ch != ' '&&ch != '\t'&&ch != '\n') {
		str.append(1, ch);
		ch = is.get();
	}
	is.ignore(1024, '\n');
	return is;
}

ostream& operator<< (ostream& os, const My_String& str) {
	os << str.c_str();
	return os;
}

istream& getline(istream& is, My_String& str, char delim) {
	str.erase();
	char ch;
	while (is.get(ch) && ch != delim) {
		str.append(1, ch);
	}
	return is;
}

istream& getline(istream& is, My_String& str) {
	str.erase();
	char ch;
	while (is.get(ch) && ch != '\n') {
		str.append(1, ch);
	}
	return is;
}

My_String operator+ (const My_String& lhs, const My_String& rhs) {
	My_String tmp(lhs);
	tmp += rhs;
	return tmp;
}

My_String operator+ (const My_String& lhs, const char* rhs) {
	My_String tmp(lhs);
	tmp += rhs;
	return tmp;
}
My_String operator+ (const char* lhs, const My_String& rhs) {
	My_String tmp(lhs);
	tmp += rhs;
	return tmp;
}

My_String operator+ (const My_String& lhs, char rhs) {
	My_String tmp(lhs);
	tmp += rhs;
	return tmp;
}

My_String operator+ (char lhs, const My_String& rhs) {
	My_String tmp(1, lhs);
	tmp += rhs;
	return tmp;
}


void swap(My_String& x, My_String& y) {
	My_String tmp = x;
	x = y;
	y = tmp;
}

bool operator==(const My_String& lhs, const My_String& rhs) {
	if (!lhs.compare(rhs)) {
		return true;
	}
	return false;
}

bool operator==(const char* lhs, const My_String& rhs) {
	if (!rhs.compare(lhs)) {
		return true;
	}
	return false;
}

bool operator==(const My_String& lhs, const char* rhs) {
	if (!lhs.compare(rhs)) {
		return true;
	}
	return false;
}

bool operator!=(const My_String& lhs, const My_String& rhs) {
	if (lhs.compare(rhs)) {
		return true;
	}
	return false;
}

bool operator!=(const char* lhs, const My_String& rhs) {
	if (rhs.compare(lhs)) {
		return true;
	}
	return false;
}

bool operator!=(const My_String& lhs, const char* rhs) {
	if (lhs.compare(rhs)) {
		return true;
	}
	return false;
}

bool operator< (const My_String& lhs, const My_String& rhs) {
	if (lhs.compare(rhs) < 0) {
		return true;
	}
	return false;
}

bool operator< (const char* lhs, const My_String& rhs) {
	if (rhs.compare(lhs) > 0) {
		return true;
	}
	return false;
}

bool operator< (const My_String& lhs, const char* rhs) {
	if (lhs.compare(rhs) < 0) {
		return true;
	}
	return false;
}

bool operator<=(const My_String& lhs, const My_String& rhs) {
	if (lhs.compare(rhs) <= 0) {
		return true;
	}
	return false;
}

bool operator<=(const char* lhs, const My_String& rhs) {
	if (rhs.compare(lhs) >= 0) {
		return true;
	}
	return false;
}

bool operator<=(const My_String& lhs, const char* rhs) {
	if (lhs.compare(rhs) <= 0) {
		return true;
	}
	return false;
}

bool operator> (const My_String& lhs, const My_String& rhs) {
	if (lhs.compare(rhs) > 0) {
		return true;
	}
	return false;
}

bool operator> (const char* lhs, const My_String& rhs) {
	if (rhs.compare(lhs) < 0) {
		return true;
	}
	return false;
}

bool operator> (const My_String& lhs, const char* rhs) {
	if (lhs.compare(rhs) > 0) {
		return true;
	}
	return false;
}

bool operator>=(const My_String& lhs, const My_String& rhs) {
	if (lhs.compare(rhs) >= 0) {
		return true;
	}
	return false;
}

bool operator>=(const char* lhs, const My_String& rhs) {
	if (rhs.compare(lhs) <= 0) {
		return true;
	}
	return false;
}

bool operator>=(const My_String& lhs, const char* rhs) {
	if (lhs.compare(rhs) >= 0) {
		return true;
	}
	return false;
}

#endif // !My_String_H