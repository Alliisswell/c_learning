#include<iostream>
using namespace std;

//���⣺�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�
//��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��

class Base {

public:

	static int m_a;

	static void func() {
		cout << "Base - static func()�ĵ��ã�" << endl;
	}

	static void func(int a) {
		cout << "Base - static func(int a)�ĵ��ã�" << endl;
	}
};
int Base::m_a = 100;

class Son :public Base {

public:

	static int m_a;

	static void func() {
		cout << "Son - static func()�ĵ��ã�" << endl;
	}
};
int Son::m_a = 200;

//ͬ����̬��Ա����
void test01() {
	//1��ͨ��������ʾ�̬��Ա����
	cout << "ͨ��������ʾ�̬��Ա���ԣ�" << endl;
	Son s;
	cout << "Son �� m_a = " << s.m_a << endl;
	cout << "Base �� m_a = " << s.Base::m_a << endl;
	//2��ͨ���������ʾ�̬��Ա����
	cout << "ͨ���������ʾ�̬��Ա���ԣ�" << endl;
	cout << "Son �� m_a = " << Son::m_a << endl;
	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������ʸ�����������
	cout << "Base �� m_a = " << Son::Base::m_a << endl;
}


//ͬ����̬��Ա����
void test02() {
	//1��ͨ��������ʾ�̬��Ա����
	cout << "ͨ��������ʾ�̬��Ա������" << endl;
	Son s;
	s.func();
	s.Base::func();
	//2��ͨ���������ʾ�̬��Ա����
	cout << "ͨ���������ʾ�̬��Ա������" << endl;
	Son::func();
	Son::Base::func();
	//������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
	//�������ʸ����б�����ͬ����Ա��������Ҫ��������
	Son::Base::func(100);

}


int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}

//�ܽ᣺ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������