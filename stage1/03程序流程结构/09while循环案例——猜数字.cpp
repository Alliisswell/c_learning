#include<iostream>

#include<ctime>//timeϵͳʱ��ͷ�ļ�����

using namespace std;

int main9()
{
	//�����������ӣ����õ�ǰϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int)time(NULL));

	//1��ϵͳ���������1-100
	int num = rand() % 100 + 1;//rand()%100����0-99�����
	//cout << num << endl;
	
	//2����ҽ��в²�
	int val = 0;
	cout << "���������Ĳ²⣺" << endl;
	while (1)
	{
		cin >> val;

		//3���ж���ҵĲ²�
		//�´�	��ʾ�²�Ľ���ǹ�����С�����·��صڶ���
		if (val > num)
		{
			cout << "�²����" << endl;
		}
		else if (val<num)
		{
			cout << "�²��С" << endl;
		}
		//�¶�	�˳���Ϸ
		else
		{
			cout << "��ϲ���¶��ˣ�" << endl;
			break;//�������øùؼ������˳���ǰѭ�� 
		}
	}
	
	system("pause");

	return 0;
}