#include<iostream>

using namespace std;

/*
switch���
���ã�**ִ�ж�������֧���
�﷨��
	switch(���ʽ)

	{

		case ���1��ִ�����;break;

		case ���2��ִ�����;break;

		...

		default:ִ�����;break;

	} 
*/

int main7()
{

	//����Ӱ���д��
	//10-9	����
	//8-7	�ǳ���
	//6-5	һ��
	//<5	��Ƭ

	//1����ʾ�û�����Ӱ���
	cout << "�����Ӱ���" << endl;
	//2���û���ʼ���д��
	int score = 0;
	cin >> score;
	cout << "����ķ���Ϊ��" <<score<< endl;
	//3�������û�����ķ�������ʾ���Ľ��
	switch (score)
	{
	case 10:
		cout << "����Ϊ�Ǿ����Ӱ" << endl; 
		break;
	case 9:
		cout << "����Ϊ�Ǿ����Ӱ" << endl; 
		break;
	case 8:
		cout << "����Ϊ��Ӱ�ǳ���" << endl; 
		break;
	case 7:
		cout << "����Ϊ��Ӱ�ǳ���" << endl; 
		break;
	case 6:
		cout << "����Ϊ��Ӱһ��" << endl; 
		break;
	case 5:
		cout << "����Ϊ��Ӱһ��" << endl; 
		break;
	default:
		cout << "����Ϊ��Ӱ����Ƭ" << endl;
		break;
	}


	system("pause");

	return 0;
}

/*
�ܽ᣺
	if��switch����
	switchȱ�㣺�ж�ʱ��ֻ�������ͻ����ַ��ͣ���������һ������
	switch�ŵ㣺�ṹ������ִ��Ч�ʸ�
*/