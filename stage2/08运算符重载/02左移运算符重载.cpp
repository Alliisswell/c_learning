#include<iostream>
using namespace std;

//���ã���������Զ�����������

class Person {

	friend ostream& operator<<(ostream& cout, Person& p);

public:

	Person(int a,int b) {
		m_a = a;
		m_b = b;
	}


	//���ó�Ա�������� ���������
	//���ǲ������ó�Ա�������� �������������Ϊ�޷�ʵ�� cout ����࣬���ֻ����ȫ�ֺ������� ���������
	//void operator<<(cout) {
	//
	//}

private:
	int m_a;
	int m_b;
};

//����ȫ�ֺ������� ���������
ostream& operator<<(ostream& out, Person& p) {
	out << "m_a = " << p.m_a << " m_b = " << p.m_b;
	return out;  //Ϊ�˿�����ʽ���
}
	 
void test01() {
	
	Person p(10,10);
	//p.m_a = 10;
	//p.m_b = 10;


	//cout << p.m_a << endl;
	//cout << p.m_b << endl;
	
	//ȫ�ֺ������ص��õı���
	//operator<<(cout, p);

	//��дΪ��
	cout << p << "\nhellow world" << endl;

}

int main() {

	test01();


	system("pause");
	return 0;
}

//�ܽ᣺������������������Ԫ����ʵ������Զ�����������