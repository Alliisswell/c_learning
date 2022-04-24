#include<iostream>
#include<string>

/*
**����������**

ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������

���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա

ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ

���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�
*/

using namespace std;

//����ѧ���ṹ��
struct Student7
{
	string sName;
	int score;
};

//������ʦ�ṹ��
struct Teacher7
{
	string tName;
	Student7 sArray[5];
};

void allocateSpace(Teacher7 tArray[], int len) {
	string nameSeed = "ABCDE";
	//����ʦ��ֵ
	for (int i = 0; i < len; i++) {	
		
		tArray[i].tName = "Teacher7_";
		tArray[i].tName += nameSeed[i];

		// ����ʦ����ѧ����ֵ
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student7_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand() % 61+40;	//40~100
			tArray[i].sArray[j].score = random;
		}
	}
}

void printInfo(Teacher7* tArray, int len) {
	for (int i = 0; i < len; i++) {
		cout << "��ʦ������" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ��������" << tArray[i].sArray[j].sName << " ���Է�����" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main7() {
	srand((unsigned int)time(NULL));
	//1������3����ʦ����
	Teacher7 tArray[3];

	//2��ͨ��������3����ʦ����Ϣ��ֵ��������ʦ����ѧ����Ϣ��ֵ
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);

	//3����ӡ������ʦ������ѧ������Ϣ
	printInfo(tArray, len);

	system("pause");

	return 0;
}