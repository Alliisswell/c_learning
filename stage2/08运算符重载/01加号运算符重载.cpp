#include<iostream>
using namespace std;

//��������ظ�������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
//���������  Ҳ���Է�����������
//���ã�ʵ�������Զ�������������ӵ�����

class Person {

public:

	//1����Ա�������� +��
	//Person operator+(Person& p) {
	//	Person temp;
	//	temp.m_a = this->m_a + p.m_a;
	//	temp.m_b = this->m_b + p.m_b;
	//	return temp;
	//}

	int m_a = 0;
	int m_b = 0;

};

//2��ȫ�ֺ������� +��
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//�������صİ汾
Person operator+(Person& p1,int num) {
	Person temp;
	temp.m_a = p1.m_a + num;
	temp.m_b = p1.m_b + num;
	return temp;
}

void test01() {
	
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;

	Person p2;
	p2.m_a = 10;
	p2.m_b = 10;
	
	//��Ա�������ص��õı���
	//Person p3 = p1.operator+(p2);

	//ȫ�ֺ������ص��õı���
	//Person p3 = operator+(p1, p2);

	//���ַ�ʽ�����Լ�дΪ��
	Person p3 = p1 + p2;

	//���������  Ҳ���Է�����������
	Person p4 = p1 + 100;	//Person + int

	cout << "p3.m_a= " << p3.m_a << endl;
	cout << "p3.m_b= " << p3.m_b << endl;

	cout << "p4.m_a= " << p4.m_a << endl;
	cout << "p4.m_b= " << p4.m_b << endl;
}


int main() {

	test01();


	system("pause");
	return 0;
}

//�ܽ�1���������õ��������͵ı��ʽ�ĵ�������ǲ����ܸı��

//�ܽ�2����Ҫ�������������

/*
#include<iostream>
using namespace std;







int main() {




	system("pause");
	return 0;
}
*/