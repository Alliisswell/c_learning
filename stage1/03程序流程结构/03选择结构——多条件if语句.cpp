#include<iostream>

using namespace std;

int main3()
{
	//1�����뿼�Է���
	int score = 0;
	cout << "������һ���˷���" << endl;
	cin >> score;

	//2����ʾ�û�����ķ���
	cout << "������ĵķ���Ϊ��" << score << endl;

	//3���ж��Ƿ���һ�� 
	if (score > 600)//ע�����if���������治Ҫ�ӷֺ�
	{
		cout << "��ϲ��������һ����ѧ��" << endl;
	}
	//�ж��Ƿ��϶���
	else if (score> 500)//�ڶ����ж�����
	{
		cout << "��ϲ�������˶�����ѧ��" << endl;
	}
	//�ж��Ƿ�������
	else if (score > 400)//�������ж�����
	{
		cout << "��ϲ��������������ѧ��" << endl;
	}
	else
	{
		cout << "���ź���û�п��ϱ��ƣ�" << endl;
	}

	system("pause");

	return 0;
}