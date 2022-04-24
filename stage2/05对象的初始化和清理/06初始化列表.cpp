#include<iostream>
using namespace std;

//作用：C++提供了初始化列表语法，用来初始化属性

//语法：构造函数():属性1(值1), 属性2（值2）... {}

//方便：参数的赋值已经在列表中完成，函数体内部可以写其他语句


class Person {
public:
	//传统初始化操作
	//Person(int a,int b,int c) {
	//	m_a = a;
	//	m_b = b;
	//	m_c = c;
	//}

	//初始化列表初始化属性
	Person(int a,int b,int c) :m_a(a), m_b(b), m_c(c) {
	}

	int m_a;
	int m_b;
	int m_c;


};

void test01() {
	
	//Person p(10,20,30);

	Person p(30,20,10);

	cout << "m_a= " << p.m_a << endl;
	cout << "m_b= " << p.m_b << endl;
	cout << "m_c= " << p.m_c << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}