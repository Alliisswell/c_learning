#include<iostream>
using namespace std;

/*
�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������

��˿��Խ��麯����Ϊ**���麯��**

���麯���﷨��`virtual ����ֵ���� ������ �������б�= 0 ;`

���������˴��麯���������Ҳ��Ϊ==������==
*/

//�������ص㣺
//1���޷�ʵ��������
//2�������������  ����Ҫ��д�����еĴ��麯��������Ҳ�޷�ʵ��������

class Base {

public:

	virtual void func() = 0;

};

class Son :public Base {

public:
	virtual void func() {
		cout << "func��������" << endl;
	}

};

void test01() {
	//Base b;	//�������޷�ʵ��������
	//new Base;	//�������޷�ʵ��������

	//Son s;	//���������д�����еĴ��麯���������޷�ʵ��������

	//��̬��̬ʹ��
	//�����ָ������� ָ���������
	Base* base = new Son;
	base->func();
}




int main() {

	test01();

	system("pause");
	return 0;
}