#include<iostream>

using namespace std;

int main1()
{
	//加减乘除
	int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;//两个整数相除，结果依然是整数，将小数部分去除

	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl;//结果是零，0.5去除小数部分就是零

	int a3 = 10;
	int b3 = 0;
	//cout << a3 / b3 << endl;//错误！两个数字相除，除数不可以为零

	//两个小数可以相除吗？
	double d1 = 0.5;
	double d2 = 0.22;
	cout << d1 / d2 << endl;//可以，运算结果可以是整数，也可以是小数



	system("pause");

	return 0;
}