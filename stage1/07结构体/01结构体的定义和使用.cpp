#include<iostream>
#include<string>

using namespace std;

//�ṹ�壺�û��Զ�����������ͣ������û��洢��ͬ���������ͣ��������ΪһЩϵͳ�ṩ������������ɵ�һ����������
//�﷨��struct �ṹ���� { �ṹ���Ա�б� }��

//ͨ���ṹ�崴�������ķ�ʽ�����֣�
//* struct �ṹ���� ������
//* struct �ṹ���� ������ = { ��Ա1ֵ �� ��Ա2ֵ... }
//* ����ṹ��ʱ˳�㴴������

//�ṹ�嶨��
struct Student1
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
};


int main1() {

	//�ṹ�����������ʽ1
	struct Student1 stu1; //struct �ؼ��ֿ���ʡ��

	stu1.name = "����";
	stu1.age = 18;
	stu1.score = 100;

	cout << "������" << stu1.name << " ���䣺" << stu1.age << " ������" << stu1.score << endl;

	//�ṹ�����������ʽ2
	struct Student1 stu2 = { "����",19,60 };

	cout << "������" << stu2.name << " ���䣺" << stu2.age << " ������" << stu2.score << endl;

//�ܽ�1������ṹ��ʱ�Ĺؼ�����struct������ʡ��

//�ܽ�2�������ṹ�����ʱ���ؼ���struct����ʡ��

//�ܽ�3���ṹ��������ò�������.�����ʳ�Ա

	system("pause");

	return 0;
}

/*

#include<iostream>
#include<string>

using namespace std;

int main(){
	


	system("pause");

	return 0;
}

*/