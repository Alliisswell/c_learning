#include<iostream>

using namespace std;

//值传递：所谓值传递，就是函数调用时，实参将数值传入给形参

//* 值传递时， == 如果形参发生，并不会影响实参 ==


//定义函数，实现两个数字进行交换
//如果函数不需要返回值，声明的时候可以写void

void swap3(int num1, int num2)
{
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return;//不需要返回值的时候，只需要写  return; 或者什么都不写
}

int main3()
{

	int a = 10;
	int b = 20;

	cout << "mian中的 a = " << a << endl;
	cout << "mian中的 b = " << b << endl;

	//当我们做值传递的时候，函数的形参发生任何的改变，并不会影响实参

	swap3(a,b);//值传递，形参发生改变

	//再输出实参，可以看到实参并没有受到影响
	cout << "mian中的 a = " << a << endl;
	cout << "mian中的 b = " << b << endl;

	system("pause");

	return 0;
}

//总结：值传递时，形参时修饰（改变）不了实参的