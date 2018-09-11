#include<iostream>
#include<cstdlib>
#include"My_String.h"
using namespace std;
using String = My_String;

int main() {
	String str = "ab1235ghijklmn";
	String sub = "123456123456";
	char subp[20] = "9999599";
	//str += "1212";
	//str += 'q';
	//cout << str.compare(sub) << endl;
	//cout << str.compare(2, 4, sub) << endl;
	//cout << str.compare(2, 4, sub, 1, 3) << endl;
	//cout << str.compare(subp) << endl;
	//cout << str.compare(2, 4, subp) << endl;
	//cout << str.compare(2, 4, subp, 1, 3) << endl;
	cin >> str;
	cout << str << endl;
	getline(cin, str,'\t');
	cout << str << endl;
	system("pause");
	return 0;
}