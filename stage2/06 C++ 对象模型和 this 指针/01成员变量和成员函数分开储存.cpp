#include<iostream>
using namespace std;


//��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//
//ֻ�зǾ�̬��Ա������������Ķ�����

class Person {
public:

	int m_a;	//�Ǿ�̬��Ա�����������������
	//int m_c;  //����һ���Ǿ�̬��Ա�����Ͷ�ռ�ö�Ӧ�������ʹ�С���ڴ�
	//int m_d;
	static int m_b;	//��̬��Ա������������������ϣ���ռ�ö�����ڴ棩

	void func() {}	//�Ǿ�̬��Ա������������������ϣ���ռ�ö�����ڴ棩

	static void func2() {}	//��̬��Ա������������������ϣ���ռ�ö�����ڴ棩

};

int Person::m_b = 0;

void test01() {
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ��1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֶ���ռ�ڴ��λ��
	//ÿһ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p = " << sizeof(p) << endl;
}

void test02() {
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}

int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;





int main() {



	system("pause");
	return 0;
}
*/
