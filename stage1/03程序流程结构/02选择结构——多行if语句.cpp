#include<iostream>

using namespace std;

int main2()
{
	//1�����뿼�Է���
	int score = 0;
	cout << "������һ���˷���" << endl;
	cin >> score;

	//2����ʾ�û�����ķ���
	cout << "������ĵķ���Ϊ��" << score << endl;

	//3���ж� �������600�֣���ӡ����һ���������ӡδ����һ��
	if (score > 600)//ע�����if���������治Ҫ�ӷֺ�
	{
		cout << "��ϲ��������һ����ѧ��" << endl;
	}
	else
	{
		cout << "��ϲ��û�п���һ����ѧ��" << endl;
	}
	system("pause");

	return 0;
}