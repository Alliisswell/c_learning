#include<iostream>
using namespace std;

//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//运算符重载  也可以发生函数重载
//作用：实现两个自定义数据类型相加的运算

class Person {

public:

	//1、成员函数重载 +号
	//Person operator+(Person& p) {
	//	Person temp;
	//	temp.m_a = this->m_a + p.m_a;
	//	temp.m_b = this->m_b + p.m_b;
	//	return temp;
	//}

	int m_a = 0;
	int m_b = 0;

};

//2、全局函数重载 +号
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//函数重载的版本
Person operator+(Person& p1,int num) {
	Person temp;
	temp.m_a = p1.m_a + num;
	temp.m_b = p1.m_b + num;
	return temp;
}

void test01() {
	
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;

	Person p2;
	p2.m_a = 10;
	p2.m_b = 10;
	
	//成员函数重载调用的本质
	//Person p3 = p1.operator+(p2);

	//全局函数重载调用的本质
	//Person p3 = operator+(p1, p2);

	//两种方式都可以简写为：
	Person p3 = p1 + p2;

	//运算符重载  也可以发生函数重载
	Person p4 = p1 + 100;	//Person + int

	cout << "p3.m_a= " << p3.m_a << endl;
	cout << "p3.m_b= " << p3.m_b << endl;

	cout << "p4.m_a= " << p4.m_a << endl;
	cout << "p4.m_b= " << p4.m_b << endl;
}


int main() {

	test01();


	system("pause");
	return 0;
}

//总结1：对于内置的数据类型的表达式的的运算符是不可能改变的

//总结2：不要滥用运算符重载

/*
#include<iostream>
using namespace std;







int main() {




	system("pause");
	return 0;
}
*/