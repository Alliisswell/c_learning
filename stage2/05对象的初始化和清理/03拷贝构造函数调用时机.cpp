#include<iostream>
using namespace std;

//拷贝构造函数调用时机

class Person {
public:
	Person() {
		cout << "Person 默认构造函数调用" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person 有参构造函数调用" << endl;
	}

	Person(const Person& p) {
		m_age = p.m_age;
		cout << "Person 拷贝构造函数调用" << endl;
	}

	~Person() {
		cout << "Person 析构函数调用" << endl;
	}

	int m_age = 0;	//年龄
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
	Person p1(20);
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << endl;;
}

//2、值传递的方式给函数参数传值
void doWork(Person p) {
	
}

void test02() {
	Person p;	//创建一个对象，会调用默认构造函数
	doWork(p);	//将 实参p 传给 形参p 过程中相当于 Person p(p);（由于是值传递 形参p 会按照 实参p 拷贝一套新的数据） 调用了拷贝构造函数
}

//3、值传递方式返回局部变量
Person doWork2() {
	Person p1;
	cout << &p1 << endl;
	return p1;
}

void test03() {
	Person p = doWork2();	//返回的Person doWork2()会按照内部的 局部变量p1 拷贝一套新的数据传给 test03中的p
							//相当于Person p(doWork2());  调用了拷贝构造函数
	cout << &p << endl;
}



int main() {

	//test01();
	//test02();
	//test03();

	system("pause");
	return 0;
}