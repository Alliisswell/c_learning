#include<iostream>

using namespace std;

/*
**���ã�** ����ѭ��������ִ��ѭ�����

**�﷨��** do{ ѭ����� } while(ѭ������);

**ע�⣺**��while����������==do...while����ִ��һ��ѭ�����==�����ж�ѭ������
*/

int main10()
{
	//����Ļ�����0��9��10������

	int num = 0;

	do
	{
		cout << num << endl;
		num++;

	} 
	while (num<10);

	system("pause");

	return 0;
}