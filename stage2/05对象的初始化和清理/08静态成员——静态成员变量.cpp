#include<iostream>
using namespace std;

//��̬��Ա����
	//�ص�
	//1�����ж��󶼹���ͬһ������
	//2������׶ξͷ����ڴ棨�����ȫ������
	//3�����������������ʼ������
	//4����ͨ��������ʾ�̬��Ա������Ҳ����ͨ������ֱ�ӽ��з���
	//5��������ʲ���  ˽��Ȩ�޵�  ��̬��Ա����

class Person {
public:

	//��������
	static int m_a;

	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static int m_b;
};

//�����ʼ����������Ҫ���������  Person::  ������ȫ�ֱ���
int Person::m_a = 100;
int Person::m_b = 300;

void test01() {
	
	Person p;
	cout << p.m_a << endl;

	//1�����ж��󶼹���ͬһ������
	Person p2;
	p2.m_a = 200;
	cout << p.m_a << endl;

}

void test02() {
	
	//��̬��Ա������������ĳ�������ϣ����ж��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ

	//1��ͨ��������з���
	//Person p;
	//cout << p.m_a << endl;

	//2��ͨ���������з��ʣ����ش�������ֱ��ͨ���������з��ʣ�
	cout << Person::m_a << endl;
	//cout << Person::m_b << endl;	//	����������ʲ���˽�о�̬��Ա����
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}

