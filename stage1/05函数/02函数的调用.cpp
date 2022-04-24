#include<iostream>

using namespace std;

//函数的调用
//**功能：** 使用定义好的函数
//
//**语法：** 函数名（参数）

//定义加法函数
//在函数定义的时候，num1和num2并没有真实数据，它只是一个形式上的参数，简称形参
int add2(int num1,int num2)
{
	int sum = num1 + num2;

	return sum;

}

int main2()
{
	//main函数中调用add函数
	int a = 10;
	int b = 20;

	//函数调用语法：函数名称（参数）
	//a和b称为实际参数，简称实参
	//当函数调用的时候，实参的值会传递给形参
	int c=add2(a, b);
	
	cout <<"c = "<< c << endl;

	a = 100;
	b = 400;

	c = add2(a, b);

	cout << "c = " << c << endl;

	system("pause");

	return 0;
}

//总结：函数定义时，函数参数列表内是形参；函数调用时，函数参数列表内是定义好的且已经初始化的实参，而且此时实参将值传给形参