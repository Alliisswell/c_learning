#include<iostream>
using namespace std;

//问题：继承中同名的静态成员在子类对象上如何进行访问？
//静态成员和非静态成员出现同名，处理方式一致

class Base {

public:

	static int m_a;

	static void func() {
		cout << "Base - static func()的调用！" << endl;
	}

	static void func(int a) {
		cout << "Base - static func(int a)的调用！" << endl;
	}
};
int Base::m_a = 100;

class Son :public Base {

public:

	static int m_a;

	static void func() {
		cout << "Son - static func()的调用！" << endl;
	}
};
int Son::m_a = 200;

//同名静态成员属性
void test01() {
	//1、通过对象访问静态成员属性
	cout << "通过对象访问静态成员属性：" << endl;
	Son s;
	cout << "Son 中 m_a = " << s.m_a << endl;
	cout << "Base 中 m_a = " << s.Base::m_a << endl;
	//2、通过类名访问静态成员属性
	cout << "通过类名访问静态成员属性：" << endl;
	cout << "Son 中 m_a = " << Son::m_a << endl;
	//第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
	cout << "Base 中 m_a = " << Son::Base::m_a << endl;
}


//同名静态成员函数
void test02() {
	//1、通过对象访问静态成员函数
	cout << "通过对象访问静态成员函数：" << endl;
	Son s;
	s.func();
	s.Base::func();
	//2、通过类名访问静态成员函数
	cout << "通过类名访问静态成员函数：" << endl;
	Son::func();
	Son::Base::func();
	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//如果想访问父类中被隐藏同名成员函数，需要加作用域
	Son::Base::func(100);

}


int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}

//总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）