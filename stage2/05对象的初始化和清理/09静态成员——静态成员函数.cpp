#include<iostream>
using namespace std;

//��̬��Ա����
//�ص㣺
//1�����ж�����ͬһ������
//2����̬��Ա����ֻ�ܷ��ʾ�̬��Ա�����������ǹ���Ȩ�޻���˽��Ȩ�ޣ�
//3����ͨ��������ʾ�̬��Ա������Ҳ����ͨ������ֱ�ӽ��з���
//4��������ʲ���  ˽��Ȩ�޵�  ��̬��Ա����

class Person {
public:

	static void func() {
		cout << "static void func�ĵ���" << endl;
		m_a = 200;  //��̬��Ա�������� ���� ��̬��Ա����
		//m_b = 200;	//������̬��Ա����ֻ�ܷ��ʾ�̬��Ա�������� m_b ���Ǿ�̬��Ա�������޷����ֵ����ĸ������ m_b ����
					//�Ǿ�̬��Ա�����������ض��������Ӧ
		m_c = 400;  //��̬��Ա�������� ˽�� ��̬��Ա����
		cout << "m_a= " << m_a << endl;
		cout << "m_c= " << m_c << endl;
	}

	static int m_a;
	int m_b;

	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static void func2() {
		cout << "static void func2�ĵ���" << endl;
	}
	
	static int m_c;
};

int Person::m_a = 100;
int Person::m_c = 300;

//���ַ��ʷ�ʽ
void test01() {
	//1��ͨ���������
	//Person p;
	//p.func();
	
	//2��ͨ���������ʣ����ش�������ֱ��ͨ���������з��ʣ�
	Person::func();

	//Person::func2();	//������ʲ��� ˽�� ��̬��Ա����

}

int main() {

	test01();

	system("pause");
	return 0;
}      

