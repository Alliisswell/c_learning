#include<iostream>
#include<string>

using namespace std;

//**���ã�** �ṹ���еĳ�Ա��������һ���ṹ��
//
//**���磺** ÿ����ʦ����һ��ѧԱ��һ����ʦ�Ľṹ���У���¼һ��ѧ���Ľṹ��

struct Student4
{
	string name;
	int age;
	int score;
};

struct Teacher4
{
	string name;
	int id;
	int age;
	
	Student4 stu;	//�ӽṹ�壬ѧ��stu
};

int main4() {

	Teacher4 tea;
	tea.name = "����";
	tea.id = 1000;
	tea.age = 40;
	tea.stu.name = "����";
	tea.stu.age = 18;
	tea.stu.score = 100;

	cout << "��ʦ������" << tea.name << " ��ʦ��ţ�" << tea.id << " ��ʦ���䣺" << tea.age << endl;
	cout << "��ʦ������ѧ��������" << tea.stu.name << " ��ʦ������ѧ�����䣺" << tea.stu.age
		<< " ��ʦ������ѧ��������" << tea.stu.score << endl;

	system("pause");

	return 0;
}

//**�ܽ᣺** �ڽṹ���п��Զ�����һ���ṹ����Ϊ��Ա���������ʵ������