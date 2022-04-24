#include<iostream>
using namespace std;

/*
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

因此可以将虚函数改为**纯虚函数**

纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0 ;`

当类中有了纯虚函数，这个类也称为==抽象类==
*/

//抽象类特点：
//1、无法实例化对象
//2、抽象类的子类  必须要重写父类中的纯虚函数，否则也无法实例化对象

class Base {

public:

	virtual void func() = 0;

};

class Son :public Base {

public:
	virtual void func() {
		cout << "func函数调用" << endl;
	}

};

void test01() {
	//Base b;	//抽象类无法实例化对象
	//new Base;	//抽象类无法实例化对象

	//Son s;	//子类必须重写父类中的纯虚函数，否则无法实例化对象

	//动态多态使用
	//父类的指针或引用 指向子类对象
	Base* base = new Son;
	base->func();
}




int main() {

	test01();

	system("pause");
	return 0;
}