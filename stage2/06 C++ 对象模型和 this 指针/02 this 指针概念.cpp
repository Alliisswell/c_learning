#include<iostream>
using namespace std;

/*
通过上节课我们知道在C++中成员变量和成员函数是分开存储的
每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分那个对象调用自己的呢？
c++通过提供特殊的对象指针，this指针，解决上述问题。**this指针指向被调用的成员函数所属的对象**

this指针是隐含在每一个非静态成员函数内的一种指针
this指针不需要定义，直接使用即可

this指针的用途：
1、当形参和成员变量同名时，可用this指针来区分
2、在类的非静态成员函数中返回对象本身，可使用return *this
*/

class Person {
public:
	Person(int age) {
		//this指针指向的是 被调用的成员函数 所属的对象
		this->age = age;
	
	}

	Person& personAddAge(Person& p) {	//注意以 引用 的方式返回，结果为40；如果不加&，而是以值传递的方式返回，结果为20
		this->age += p.age;
		return *this;	//this指针p2的指针，而*this指向的就是p2这个对象本体
	}

	int age;
};

//1、解决名称冲突
void test01() {
	Person p1(10);  //p1调用有参构造函数，this指针就指向p1
	cout << "p1的年龄为：" << p1.age << endl;

	Person p2(20);
	cout << "p2的年龄为：" << p2.age << endl;
}

//2、返回对象本身用 *this
void test02() {
	Person p1(10);

	Person p2(10);

	p2.personAddAge(p1).personAddAge(p1).personAddAge(p2);	//链式编程思想

	cout << "p2的年龄为：" << p2.age << endl;
}

int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}