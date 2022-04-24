#include<iostream>

using namespace std;

int main2() {
	
	//1、引用必须初始化
	int a = 10;
	//int& b;	//错误，必须要初始化
	int& b = a;
	int& d = b;  //引用可以多对一，就是可以有很多个别名，b和d都是a的别名,并且别名b可以作为原名再次被引用

	//2、引用在初始化后，不可以改变（不可以更被改引用对象）
	int c = 20;
	b = c;	//这是赋值操作，是合法的
	//int& b = c;	//错误，b 引用 a 后,不可以更改被引用对象

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;

	system("pause");
	return 0;
}