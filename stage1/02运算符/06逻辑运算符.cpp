#include<iostream>

using namespace std;

int main6()
{
	//�߼������  ���ڸ��ݱ��ʽ��ֵ������ֵ���ֵ
	int a;
	int b;
	//��
	a = 10;  //c++�У������㶼Ϊ��
	cout << !a << endl;//���ؽ��Ϊ��

	//��
	a = 10;
	b = 10;
	cout << (a && b) << endl;//���ؽ��Ϊ�棬��Ϊͬ���Ϊ�棬�����һ��Ϊ�٣�����Ϊ��

	//��
	a = 0;
	b = 0;
	cout << (a || b) << endl;//���ؽ��Ϊ�٣���Ϊͬ�ٲ�Ϊ�٣������һ��Ϊ�棬����Ϊ��

	system("pause");

	return 0;
}