#include<iostream>
#include<string>

using namespace std;

//**���ã�** ͨ��ָ����ʽṹ���еĳ�Ա
//���ò����� ��->�� ����ͨ���ṹ��ָ����ʽṹ������

//����ѧ���ṹ��
struct Student3
{
	string name;
	int age;
	int score;
};

int main3() {

	//����ѧ���ṹ�����
	Student3 stu = {"����",18,100};
	
	//ͨ��ָ��ָ��ṹ�����
	Student3* p = &stu;	//ָ�����������Ϊ Student3
	cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;

	system("pause");
	return 0;
}