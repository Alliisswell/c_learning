#include<iostream>
using namespace std;

//��������
//��Ա����  ��  ��const�����ǳ�Ϊ�������Ϊ ������
//�������ڲ������޸ĳ�Ա����
//��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

//������
//��������  ǰ  ��const���Ƹö���Ϊ ������
//������ֻ�ܵ��ó�����
//�������mutable��Ա����Ҳ�ǿ����޸ĵģ�mutable��ǿ��


class Person {
public:
	//thisָ��ı��� ��ָ�볣�� Person* const this; ָ���ָ���ǲ������޸ĵ�
	//�ڳ�Ա������߼�const�����ε���thisָ�룬��ָ��ָ���ֵҲ�������޸�
	void showPerson() const {	//����const ֮��Ĭ�ϵ�thisָ���Ϊ��const Person* const this;
		//this->m_a = 100;	//ÿһ����Ա�����ڲ�����Ĭ��һ��thisָ�룬m_a === this->m_a
		//this = NULL;	//thisָ�벻�����޸�ָ���ָ��
		this->m_b = 100;
	}

	void func() {
	
	}

	int m_a = 0;
	mutable int m_b = 0;	//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};

void test01() {
	Person p;
	p.showPerson();
}

//������
//��������ǰ��const�Ƹö���Ϊ������
//������ֻ�ܵ��ó�����

void test02() {
	const Person p;	//�ڶ���ǰ��const����Ϊ������
	//p.m_a = 100;	//����m_a ǰû�м� mutable
	p.m_b = 100;	//û�б���m_b ������������ڳ�������Ҳ�����޸�
	//������ֻ�ܵ��ó�����
	p.showPerson();
	//p.func();	//���ǳ�����

}

int main() {


	system("pause");
	return 0;
}