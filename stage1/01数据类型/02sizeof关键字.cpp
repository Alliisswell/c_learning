#include<iostream>

using namespace std;

int main2()
{
	//���ͣ�short(2)	int(4)	  long(4)    long long(8)		
	//��������sizeof�����������ռ��ռ���ڴ��С
	//�﷨��sizeof(��������/����)
	
	short num1 = 10;
	cout << "shortռ���ڴ�ռ�Ϊ�� " <<sizeof(short)<< endl;

	long long num2 = 10;
	cout << "long longռ���ڴ�ռ�Ϊ�� " << sizeof(num2) << endl;

	//�������ݴ�С�Ƚϣ�
	//short < int <= long <= long long 

	system("pause");

	return 0;
}