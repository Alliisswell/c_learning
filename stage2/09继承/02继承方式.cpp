#include<iostream>
using namespace std;

class Base {

public:
	int m_a = 0;
protected:
	int m_b = 0;
private:
	int m_c = 0;
};

//�����̳�
class Son1 :public Base {

public:
	void func() {
		m_a = 10;	//�����еĹ���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
		m_b = 10;	//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
		//m_c = 10;	//�����е�˽��Ȩ�޳�Ա��������ʲ���
	}
};

void test01() {
	Son1 s1;
	s1.m_a = 100;
	//s1.m_b = 100;	//��Son1�У�m_b �Ǳ���Ȩ�ޣ�������ʲ���
}

//�����̳�
class Son2 :protected Base {
public:
	void func() {
		m_a = 10;	//�����еĹ���Ȩ�޳�Ա���������б�Ϊ����Ȩ��
		m_b = 10;	//�����еĹ���Ȩ�޳�Ա���������б�Ϊ����Ȩ��
		//m_c = 10;	//�����е�˽��Ȩ�޳�Ա��������ʲ���
	}
};

void test02() {
	Son2 s2;
	//s2.m_a = 100;	//��Son2�У�m_a ��Ϊ����Ȩ�ޣ�������ʲ���
	//s2.m_b = 100;	//��Son2�У�m_b ��Ϊ����Ȩ�ޣ�������ʲ���
}

//˽�м̳�
class Son3 :private Base {
public:
	void func() {
		m_a = 10;	//�����еĹ���Ȩ�޳�Ա���������б�Ϊ˽��Ȩ��
		m_b = 10;	//�����еĹ���Ȩ�޳�Ա���������б�Ϊ˽��Ȩ��
		//m_c = 10;	//�����е�˽��Ȩ�޳�Ա��������ʲ���
	}
};

void test03() {
	Son3 s3;
	//s3.m_a = 100;	//��Son3�У�m_a ��Ϊ˽��Ȩ�ޣ�������ʲ���
	//s3.m_b = 100;	//��Son3�У�m_b ��Ϊ˽��Ȩ�ޣ�������ʲ���
}

//�ٴ���֤����Son3�У�m_a �� m_b ��Ϊ˽��Ȩ�ޣ�������ʲ�����
class GrandSon3 :public Son3 {	//���ڸ��� Son3 �� m_a �� m_b ��˽�г�Ա����ʹ�ǹ����̳з�ʽ��Ҳ���ʲ���
public:
	void func() {
		//m_a = 1000;	//���� Son3 �е�˽��Ȩ�޳�Ա������ GrandSon3 ���ʲ���
		//m_b = 1000;	//���� Son3 �е�˽��Ȩ�޳�Ա������ GrandSon3 ���ʲ���
	}

};

int main() {



	system("pause");
	return 0;
}