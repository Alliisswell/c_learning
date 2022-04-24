#include<iostream>
using namespace std;


//在C++中，类内的成员变量和成员函数分开存储
//
//只有非静态成员变量才属于类的对象上

class Person {
public:

	int m_a;	//非静态成员变量，属于类对象上
	//int m_c;  //增加一个非静态成员变量就多占用对应数据类型大小的内存
	//int m_d;
	static int m_b;	//静态成员变量，不属于类对象上（不占用对象的内存）

	void func() {}	//非静态成员函数，不属于类对象上（不占用对象的内存）

	static void func2() {}	//静态成员函数，不属于类对象上（不占用对象的内存）

};

int Person::m_b = 0;

void test01() {
	Person p;
	//空对象占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分对象占内存的位置
	//每一个空对象也应该有一个独一无二的内存地址
	cout << "size of p = " << sizeof(p) << endl;
}

void test02() {
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}

int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;





int main() {



	system("pause");
	return 0;
}
*/
