#include<iostream>

using namespace std;

//���ַ���Ȩ��
//����Ȩ�� public		��Ա ���ڿ��Է��� ������Է���
//����Ȩ�� protected	��Ա ���ڿ��Է��� ���ⲻ���Է��� ���ӿ��Է��ʸ����еı�������
//˽��Ȩ�� private		��Ա ���ڿ��Է��� ���ⲻ���Է��� ���Ӳ����Է��ʸ��׵�˽������

class Person {
public:
	//����Ȩ��
	string m_name;

protected:
	//����Ȩ��
	string m_car;

private:
	//˽��Ȩ��
	int m_password;

public:	//�˴���Ȩ����𣬹涨���ǽ�����д�� ��Ϊ �ı�����Ȩ��
	void func() {	//���ڿ��Է���
		m_name = "����";
		m_car = "������";
		m_password = 123456;
	}
};


int main() {

	//ʵ�����������
	Person p1;

	p1.m_name = "����";
	//p1.m_car = "����";	//����Ȩ�����ݣ���������ʲ���
	//p1.m_password = 123;  //˽��Ȩ�����ݣ���������ʲ���

	p1.func();  //�˳�Ա����Ȩ��Ϊ����Ȩ�ޣ����Է��ʣ����ᱨ��




	system("pause");
	return 0;
}