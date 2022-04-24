#include<iostream>
using namespace std;

//静态成员变量
	//特点
	//1、所有对象都共享同一份数据
	//2、编译阶段就分配内存（存放在全局区）
	//3、类内声明，类外初始化操作
	//4、可通过对象访问静态成员变量，也可以通过类名直接进行访问
	//5、类外访问不到  私有权限的  静态成员变量

class Person {
public:

	//类内声明
	static int m_a;

	//静态成员变量也是有访问权限的
private:
	static int m_b;
};

//类外初始化操作，需要添加作用域  Person::  否则将是全局变量
int Person::m_a = 100;
int Person::m_b = 300;

void test01() {
	
	Person p;
	cout << p.m_a << endl;

	//1、所有对象都共享同一份数据
	Person p2;
	p2.m_a = 200;
	cout << p.m_a << endl;

}

void test02() {
	
	//静态成员变量，不属于某个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1、通过对象进行访问
	//Person p;
	//cout << p.m_a << endl;

	//2、通过类名进行访问（不必创建对象，直接通过类名进行访问）
	cout << Person::m_a << endl;
	//cout << Person::m_b << endl;	//	报错，类外访问不到私有静态成员变量
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}

