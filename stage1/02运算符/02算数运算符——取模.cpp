#include<iostream>

using namespace std;

int main2()
{
	//ȡģ���� ���ʣ�����������

	int a1 = 10;
	int b1 = 3;
	cout << a1 % b1 << endl;  //����Ϊ1

	int a2 = 10;
	int b2 = 20;
	cout << a2 % b2 << endl;  //����Ϊ10

	int a3 = 10;
	int b3 = 0;
	//cout << a3 % b3 << endl;  //�����������������������Ϊ�㣬����Ҳ������ȡģ����

	//����С���ǲ�������ȡģ�����
	double d1 = 3.14;
	double d2 = 0.22;
	//cout << d1 % d2 << endl;  //����

	system("pause");

	return 0;
}