#include<iostream>
using namespace std;

//静态成员函数
//特点：
//1、所有对象共享同一个函数
//2、静态成员函数只能访问静态成员变量（无论是公共权限还是私有权限）
//3、可通过对象访问静态成员变量，也可以通过类名直接进行访问
//4、类外访问不到  私有权限的  静态成员函数

class Person {
public:

	static void func() {
		cout << "static void func的调用" << endl;
		m_a = 200;  //静态成员函数访问 共有 静态成员变量
		//m_b = 200;	//报错，静态成员函数只能访问静态成员变量，而 m_b 不是静态成员变量，无法区分到底哪个对象的 m_b 属性
					//非静态成员变量必须与特定对象相对应
		m_c = 400;  //静态成员函数访问 私有 静态成员变量
		cout << "m_a= " << m_a << endl;
		cout << "m_c= " << m_c << endl;
	}

	static int m_a;
	int m_b;

	//静态成员函数也是有访问权限的
private:
	static void func2() {
		cout << "static void func2的调用" << endl;
	}
	
	static int m_c;
};

int Person::m_a = 100;
int Person::m_c = 300;

//两种访问方式
void test01() {
	//1、通过对象访问
	//Person p;
	//p.func();
	
	//2、通过类名访问（不必创建对象，直接通过类名进行访问）
	Person::func();

	//Person::func2();	//类外访问不到 私有 静态成员函数

}

int main() {

	test01();

	system("pause");
	return 0;
}      

