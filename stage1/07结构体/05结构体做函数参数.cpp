#include<iostream>
#include<string>

using namespace std;

//**���ã�** ���ṹ����Ϊ���������д���

//���ݷ�ʽ�����֣�
//* ֵ����
//* ��ַ����

struct Student5
{
	string name;
	int age;
	int score;
};

void printStudent1(Student5 s) {
	s.age = 80;
	cout << "�Ӻ�����������" << s.name << " ���䣺" << s.age
		<< " ������" << s.score << endl;
}

void printStudent2(Student5* s) {
	s->age = 80;
	cout << "�Ӻ�����������" << s->name << " ���䣺" << s->age
		<< " ������" << s->score << endl;
}

int main5() {
	//�����ṹ�����
	Student5 stu= {"����",18,100};

	//��ѧ�����뵽һ�������У���ӡѧ�����ϵ�������Ϣ
	
	//ֵ����
	//printStudent1(stu);
	
	//��ַ����
	printStudent2(&stu);

	cout << "������" << stu.name << " ���䣺" << stu.age
		<< " ������" << stu.score << endl;	//�Ա����



	system("pause");

	return 0;
}

//�ܽ᣺��������޸��������е����ݣ���ֵ���ݣ���֮�õ�ַ����