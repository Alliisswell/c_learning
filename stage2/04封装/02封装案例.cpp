#include<iostream>
#include<string>

using namespace std;

//���һ��ѧ����
//������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��

//ѧ����
class Student {
public:	//����Ȩ��

	//���е����Ժ���Ϊ ����ͳһ��Ϊ ��Ա
	//����Ҳ��Ϊ ��Ա���� �� ��Ա����
	//��ΪҲ��Ϊ ��Ա���� �� ��Ա����

	//����
	string m_name;	//����
	int m_id = 0;	//ѧ��

	//��Ϊ
	//��ʾ������ѧ��
	void showStudent() {
		cout << "������" << m_name << "\tѧ�ţ�" << m_id << endl;
	}

	//��������ֵ
	void setName(string name) {
		m_name = name;
	}

	//��ѧ�Ÿ�ֵ
	void setId(int id) {
		m_id = id;
	}

};
int main() {

	//ʵ���� ͨ��ѧ���ഴ��һ��ѧ������
	Student s1;
	//��s1���� �������Ը�ֵ����
	/*s1.m_name = "����";
	s1.m_id = 209802020;
	s1.showStudent();*/

	s1.setName("����");
	s1.setId(219802020);
	s1.showStudent();

	system("pause");
	return 0;
}