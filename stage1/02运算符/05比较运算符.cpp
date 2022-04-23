#include<iostream>

using namespace std;

int main5()
{
	//比较运算符  用于表达式的比较，并返回一个真值或假值
	int a = 10;
	int b = 20;
	// ==
	cout << (a == b) << endl;  //加小括号，提高运算符的优先级，如果不加会报错！

	// !=
	cout << (a != b) << endl;

	// <
	cout << (a < b) << endl;

	// >
	cout << (a > b) << endl;

	// <=
	cout << (a <= b) << endl;

	// >=
	cout << (a >= b) << endl;
	system("pause");

	return 0;
}