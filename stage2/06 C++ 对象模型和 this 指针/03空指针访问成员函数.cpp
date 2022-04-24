#include<iostream>
using namespace std;

//空指针调用成员函数

//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

//如果用到this指针，需要加以判断保证代码的健壮性（即先判断指针是否为空）

class Person {
public:

	void showClassName() {
		cout << "this is Person class" << endl;
	}

	void showPersonAge() {
		//报错原因是因为传入的指针是 NULL

		if (this == NULL) {
			return;
		}

		cout << "age= " << m_age << endl;	//每一个成员函数内部都会默认一个this指针，m_age === this->m_age 
	}

	int m_age = 0;
};

void test01() {
	Person* p= NULL;
	p->showClassName();
	p->showPersonAge();	//报错原因是因为传入的指针是 NULL

}

int main() {

	test01();

	system("pause");
	return 0;
}