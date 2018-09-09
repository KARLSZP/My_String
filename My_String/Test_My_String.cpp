#include<iostream>
#include<cstdlib>
#include"My_String.h"
using namespace std;
using String = My_String;

int main() {
	String str;
	String sub = "dsd";
	str = sub;
	cout << str.at(3) << endl;
	system("pause");
	return 0;
}