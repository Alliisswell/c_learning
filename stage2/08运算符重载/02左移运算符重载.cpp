#include<iostream>
using namespace std;

//作用：可以输出自定义数据类型

class Person {

	friend ostream& operator<<(ostream& cout, Person& p);

public:

	Person(int a,int b) {
		m_a = a;
		m_b = b;
	}


	//利用成员函数重载 左移运算符
	//我们不会利用成员函数重载 左移运算符，因为无法实现 cout 在左侧，因此只能用全局函数重载 左移运算符
	//void operator<<(cout) {
	//
	//}

private:
	int m_a;
	int m_b;
};

//利用全局函数重载 左移运算符
ostream& operator<<(ostream& out, Person& p) {
	out << "m_a = " << p.m_a << " m_b = " << p.m_b;
	return out;  //为了可以链式编程
}
	 
void test01() {
	
	Person p(10,10);
	//p.m_a = 10;
	//p.m_b = 10;


	//cout << p.m_a << endl;
	//cout << p.m_b << endl;
	
	//全局函数重载调用的本质
	//operator<<(cout, p);

	//简写为：
	cout << p << "\nhellow world" << endl;

}

int main() {

	test01();


	system("pause");
	return 0;
}

//总结：重载左移运算符配合友元可以实现输出自定义数据类型