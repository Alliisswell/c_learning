#include<iostream>
using namespace std;
#include<string>

//C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ �����Ա

//�ֻ���
class Phone {
public:

	Phone(string name):m_pname(name) {
		cout << "Phone���вι��캯������" << endl;

	}

	~Phone() {
		cout << "Phone��������������" << endl;
	}

	string m_pname;

};
//����
class Person {
public:
	//m_phone(pname) === Phone m_phone = pname; ��������ʽת���������ֻ�����вι��캯��
	Person(string name,string pname):m_name(name),m_phone(pname) {  
		cout << "Person���вι��캯������" << endl;
	}
	
	~Person() {
		cout << "Person��������������" << endl;
	}

	string m_name;	//��������ͨ�������͵ĳ�Ա���ԣ�

	Phone m_phone;	//�ֻ���һ���������͵ĳ�Ա���ԣ�

};

//�������������Ϊ�����Ա������ʱ �ȹ�������ٹ�������
//��ô����������˳���أ�	������˳���빹���෴  ����Ϊ  ջ�����ݣ��Ƚ�����������������ȱ��ͷţ�������ͷ�

void test01() {
	Person p("����","��Ϊ");
	cout << "������" << p.m_name << "\t�ֻ���" << p.m_phone.m_pname << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//�ܽ᣺ջ�����ݣ��Ƚ����