#include<iostream>

using namespace std;

int main6()
{
	//逻辑运算符  用于根据表达式的值返回真值或假值
	int a;
	int b;
	//非
	a = 10;  //c++中，除了零都为真
	cout << !a << endl;//返回结果为假

	//与
	a = 10;
	b = 10;
	cout << (a && b) << endl;//返回结果为真，因为同真才为真，如果有一个为假，则结果为假

	//或
	a = 0;
	b = 0;
	cout << (a || b) << endl;//返回结果为假，因为同假才为假，如果有一个为真，则结果为真

	system("pause");

	return 0;
}