#include<iostream>
#include<cstdlib>
#include"My_String.h"
using namespace std;
using String = My_String;

int main() {
	String str = "abcdefghijklmn";
	String sub = "123456";
	str.pop_back();
	//str += "1212";
	//str += 'q';
	cout << str << endl << sub;
	system("pause");
	return 0;
}