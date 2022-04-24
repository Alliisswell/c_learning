#include<iostream>
using namespace std;

class Base1 {

public:
	Base1() {
		m_a = 100;
	}
	int m_a;
};

class Base2 {

public:
	Base2() {
		m_a = 200;
	}
	int m_a;
};

//创建子类  需要继承Base1和Base2
//语法：class 子类 :继承方式 父类1, 继承方式 父类2 {}
class Son :public Base1, public Base2 {

public:
	Son() {
		m_c = 300;
		m_d = 400;
	}

	int m_c;
	int m_d;
};

void test01() {
	Son s;
	
	cout << "size of Son = " << sizeof(Son) << endl;
	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1::m_a = " << s.Base1::m_a << endl;
	cout << "Base2::m_a = " << s.Base2::m_a << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//C++实际开发中不建议用多继承