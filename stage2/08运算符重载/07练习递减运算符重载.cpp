#include<iostream>
using namespace std;

class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger& myint);

public:
	MyInteger() {
		m_num = 0;
	}

	MyInteger& operator--() {
		m_num--;
		return *this;
	}

	MyInteger& operator--(int) {  //这里不用引用返回会报错，不知道原因
		MyInteger temp = *this;
		m_num--;
		return temp;
	}

private:
	int m_num;

};

ostream& operator<<(ostream& out, MyInteger& myint) {
	out << myint.m_num;
	return out;
}

void test01() {

	MyInteger myint;
	//cout << --(--myint) << endl;
	//cout << myint << endl;
	cout << --(--myint) << " " << myint << endl;
}

void test02() {
	MyInteger myint;
	cout << myint-- << endl;
	cout << myint << endl;
	//cout << myint-- << " " << myint << endl;  //后置递减有问题
}


int main() {

	test01();
	test02();

	system("pause");
	return 0;
}