#include<iostream>
#include<string>

using namespace std;

//**���ã�** ��const����ֹ�����

struct Student6
{
	string name;
	int age;
	int score;
};

void printStudent6(const Student6* s) {	////��const��ֹ�������е������
	//s->age = 80;	////����ʧ�ܣ���Ϊ����const����
	cout << "�Ӻ�����������" << s->name << " ���䣺" << s->age
		<< " ������" << s->score << endl;
}

int main6() {

	Student6 stu = { "����",18,100 };

	printStudent6(&stu);

	system("pause");

	return 0;
}