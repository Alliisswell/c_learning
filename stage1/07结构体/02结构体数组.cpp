#include<iostream>
#include<string>

using namespace std;

//�ṹ������
//**���ã�** ���Զ���Ľṹ����뵽�����з���ά��
//**�﷨��** struct  �ṹ���� ������[Ԫ�ظ���] = { {} , {} , ... {} }

//1������ṹ��
struct Student2 
{
	//��Ա�б�
	string name;	//����
	int age;	//����
	int score;	//����
};

int main2() {
	//2�������ṹ������ 
	struct Student2 stuArray[3] = {
		{"����",18,100},
		{"����",28,88},
		{"����",38,66}
	};
	
	//3�����ṹ�������е�Ԫ�ظ�ֵ
	//stuArray[2] = {"����",48,60};
	stuArray[2].name = "����";
	stuArray[2].age = 48;
	stuArray[2].score = 60;
	
	//4�������ṹ������
	for (int i = 0; i < 3; i++) {
		cout << "������" << stuArray[i].name << " ���䣺" << stuArray[i].age << " �ɼ���" << stuArray[i].score << endl;
	}
	system("pause");

	return 0;
}