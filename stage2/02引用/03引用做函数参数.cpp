#include<iostream>

using namespace std;

//**作用：** 函数传参时，可以利用引用的技术让形参修饰实参
//
//**优点：** 可以简化指针修改实参

//例子：交换函数

//1、值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "swap01a= " << a << endl;
	cout << "swap01b= " << b << endl;
}
//2、地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	cout << "swap02a= " << *a << endl;
	cout << "swap02b= " << *b << endl;

}
//3、引用传递
void mySwap03(int& a, int& b) {	//这里形参a,b是实参a,b的别名
	int temp = a;
	a = b;
	b = temp;

	cout << "swap03a= " << a << endl;
	cout << "swap03b= " << b << endl;
}

int main3() {

	int a = 10;
	int b = 20;

	//mySwap01(a, b);	//值传递，形参不可以修饰实参
	//mySwap02(&a, &b);	//地址传递，形参可以修饰实参
	mySwap03(a, b);	//引用传递，形参也可以修饰实参


	cout << "a= " << a << endl;
	cout << "b= " << b << endl;


	system("pause");
	return 0;
}

//总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单