#include<iostream>

using namespace std;

//引用做函数的返回值

//1、不要返回局部变量的引用
int& test01() {
	int a = 10;	//局部变量存放在四区中的 栈区
	return a;
}

//2、函数调用可以作为左值
int& test02() {
	static int a = 10;	//静态变量，存放在全局区，全局区上的数据在程序结束后由操作系统释放
	return a;  //以引用的方式返回全局区的变量，相当于做了一次引用，别名就是函数名 === int& test02() = a;
}

int main4() {

	int& ref1 = test01();

	cout << "ref1= " << ref1 << endl;	//错误，因为a的内存已经释放
	
	int& ref2 = test02();	//test02就是静态变量a的别名，然后又被ref2所引用

	cout << "ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;

	test02() = 1000;	//如果函数的返回值是引用，这个函数调用可以作为左值（左值就是等号左边的东西），是赋值操作

	cout << "ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;



	system("pause");
	return 0;
}