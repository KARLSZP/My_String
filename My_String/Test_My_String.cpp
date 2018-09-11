#include<iostream>
#include<cstdlib>
#include"My_String.h"
using namespace std;
using String = My_String;

int main() {
	String str = "abcdefghijklmn";
	String sub = "123456123456";
	String subp = "12345";
	//str += "1212";
	//str += 'q';
	cout << sub.rfind("23488",5);
	system("pause");
	return 0;
}