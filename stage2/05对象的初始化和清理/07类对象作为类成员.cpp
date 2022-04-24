#include<iostream>
using namespace std;
#include<string>

//C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员

//手机类
class Phone {
public:

	Phone(string name):m_pname(name) {
		cout << "Phone的有参构造函数调用" << endl;

	}

	~Phone() {
		cout << "Phone的析构函数调用" << endl;
	}

	string m_pname;

};
//人类
class Person {
public:
	//m_phone(pname) === Phone m_phone = pname; 这是用隐式转换法调用手机类的有参构造函数
	Person(string name,string pname):m_name(name),m_phone(pname) {  
		cout << "Person的有参构造函数调用" << endl;
	}
	
	~Person() {
		cout << "Person的析构函数调用" << endl;
	}

	string m_name;	//姓名（普通数据类型的成员属性）

	Phone m_phone;	//手机（一个对象类型的成员属性）

};

//当其他类对象作为本类成员，构造时 先构造对象，再构造自身
//那么析构函数的顺序呢？	析构的顺序与构造相反  是因为  栈上数据，先进后出，所以是自身先被释放，对象后被释放

void test01() {
	Person p("张三","华为");
	cout << "姓名：" << p.m_name << "\t手机：" << p.m_phone.m_pname << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//总结：栈上数据，先进后出