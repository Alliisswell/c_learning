#include<iostream>

using namespace std;

int main7()
{
	//����bool��������
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;

	//������ 1������ 0�����

	flag = 1;
	cout << flag << endl;

	flag = 0;
	cout << flag << endl;

	flag = 10;  //���㶼����
	cout << flag << endl;

	//�鿴bool������ռ�ڴ�ռ��С 1���ֽ�
	cout << "bool������ռ�ڴ�ռ�Ϊ��" << sizeof(bool) << endl;

	system("pause");

	return 0;
}