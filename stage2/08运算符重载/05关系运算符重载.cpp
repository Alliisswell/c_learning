#include<iostream>
using namespace std;

//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

class Person {

public:

	Person(string name,int age) {
		m_name = name;
		m_age = age;
	}

	//重载 == 号
	bool operator==(Person& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return true;
		}
		return false;
	}

	bool operator!=(Person& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return false;
		}
		return true;
	}

	string m_name;
	int m_age;
};

void test01() {
	Person p1("Tom",18);
	Person p2("Tom",18);

	if (p1 == p2) {
		cout << "p1 和 p2 是相等的！" << endl;
	}
	else {
		cout << "p1 和 p2 是不相等的！ " << endl;
	}

	if (p1 != p2) {
		cout << "p1 和 p2 是不相等的！" << endl;
	}
	else {
		cout << "p1 和 p2 是相等的！ " << endl;
	}
}

int main() {

	test01();


	system("pause");
	return 0;
}