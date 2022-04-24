#include<iostream>
using namespace std;

//常函数：
//成员函数  后  加const后我们称为这个函数为 常函数
//常函数内不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改

//常对象：
//声明对象  前  加const，称该对象为 常对象
//常对象只能调用常函数
//常对象的mutable成员属性也是可以修改的（mutable很强）


class Person {
public:
	//this指针的本质 是指针常量 Person* const this; 指针的指向是不可以修改的
	//在成员函数后边加const，修饰的是this指针，让指针指向的值也不可以修改
	void showPerson() const {	//加了const 之后，默认的this指针变为：const Person* const this;
		//this->m_a = 100;	//每一个成员函数内部都会默认一个this指针，m_a === this->m_a
		//this = NULL;	//this指针不可以修改指针的指向
		this->m_b = 100;
	}

	void func() {
	
	}

	int m_a = 0;
	mutable int m_b = 0;	//特殊变量，即使在常函数中，也可以修改这个值
};

void test01() {
	Person p;
	p.showPerson();
}

//常对象：
//声明对象前加const称该对象为常对象
//常对象只能调用常函数

void test02() {
	const Person p;	//在对象前加const，变为常对象
	//p.m_a = 100;	//报错，m_a 前没有加 mutable
	p.m_b = 100;	//没有报错，m_b 是特殊变量，在常对象下也可以修改
	//常对象只能调用常函数
	p.showPerson();
	//p.func();	//不是常函数

}

int main() {


	system("pause");
	return 0;
}