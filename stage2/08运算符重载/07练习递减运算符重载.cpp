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

	MyInteger& operator--(int) {  //���ﲻ�����÷��ػᱨ����֪��ԭ��
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
	//cout << myint-- << " " << myint << endl;  //���õݼ�������
}


int main() {

	test01();
	test02();

	system("pause");
	return 0;
}