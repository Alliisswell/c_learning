#include<iostream>
using namespace std;

//�������캯������ʱ��

class Person {
public:
	Person() {
		cout << "Person Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person �вι��캯������" << endl;
	}

	Person(const Person& p) {
		m_age = p.m_age;
		cout << "Person �������캯������" << endl;
	}

	~Person() {
		cout << "Person ������������" << endl;
	}

	int m_age = 0;	//����
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {
	Person p1(20);
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << endl;;
}

//2��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p) {
	
}

void test02() {
	Person p;	//����һ�����󣬻����Ĭ�Ϲ��캯��
	doWork(p);	//�� ʵ��p ���� �β�p �������൱�� Person p(p);��������ֵ���� �β�p �ᰴ�� ʵ��p ����һ���µ����ݣ� �����˿������캯��
}

//3��ֵ���ݷ�ʽ���ؾֲ�����
Person doWork2() {
	Person p1;
	cout << &p1 << endl;
	return p1;
}

void test03() {
	Person p = doWork2();	//���ص�Person doWork2()�ᰴ���ڲ��� �ֲ�����p1 ����һ���µ����ݴ��� test03�е�p
							//�൱��Person p(doWork2());  �����˿������캯��
	cout << &p << endl;
}



int main() {

	//test01();
	//test02();
	//test03();

	system("pause");
	return 0;
}