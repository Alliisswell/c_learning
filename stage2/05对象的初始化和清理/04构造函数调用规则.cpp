#include<iostream>
using namespace std;

//创建一个类，C++编译器会给每个类都添加至少三个函数
//1．默认构造函数(无参，函数体为空)
//2．默认析构函数(无参，函数体为空)
//3．默认拷贝构造函数，对属性进行值拷贝

//构造函数调用规则如下：
//
//* 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
//
//
//* 如果用户定义拷贝构造函数，c++不会再提供其他构造函数

class Person {
public:
	//Person() {
	//	cout << "Person的默认构造函数调用" << endl;
	//}

	//Person(int age) {
	//	cout << "Person的有参构造函数调用" << endl;
	//	m_age = age;
	//}

	Person(const Person& p) {
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
	}

	~Person() {
		cout << "Person的析构函数调用" << endl;
	}

	int m_age = 0;	//年龄
};

//2.1、如果我们写了有参构造函数，编译器就不再提供默认构造，但是依然提供拷贝构造

//void test01() {
//	Person p;
//	p.m_age = 18;
//
//	Person p2(p);
//
//	cout << "p2的年龄为：" << p.m_age << endl;
//}

//2.2、如果我们写了拷贝构造函数，编译器就不再提供其他普通构造函数了

void test02() {
	
	//为了验证，注释掉默认和有参，留有拷贝，相当于写了拷贝，验证会不会再提供其他普通构造函数
	//调用默认就会报错：没有默认构造可用
	//调用有参就会报错：没有有参构造可用
	//Person p;
	//Person p(28);
	
}

int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}
