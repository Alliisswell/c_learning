#include<iostream>

using namespace std;

//常量引用
//作用：常量引用主要用来修饰形参，防止误操作
//使用场景：在函数形参列表中，可以加 const 修饰形参，防止形参改变实参

void showValue(const int& val) {
	//val = 1000;
	cout << "val= " << val << endl;
}

int main6() {

	//int a = 10;
		
	//int& ref = 10;	//错误，引用必须引用一块合法的内存，比如栈区或堆区的内存，而 10 是常量...
	//int& ref = a;	//这是合法的，局部变量 a 在栈区
	//const int& ref = 10;	//加上const之后，编译器讲代码修改 int temp = 10; const int& ref = temp;
	//ref = 20;	//加上const之后变为只读，不可以修改

	int a = 100;
	showValue(a);
	cout << "a= " << a << endl;

	system("pause");
	return 0;
}