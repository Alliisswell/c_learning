#include<iostream>
#include"swap.h"
using namespace std;


/*
### 6.7 �����ķ��ļ���д

**���ã�**�ô���ṹ��������

�������ļ���дһ����4������

1. ������׺��Ϊ.h��ͷ�ļ�
2. ������׺��Ϊ.cpp��Դ�ļ�
3. ��ͷ�ļ���д����������
4. ��Դ�ļ���д�����Ķ���

*/



//ʵ���������ֽ����ĺ���

////����������
//void swap(int a,int b);
////�����Ķ���
//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//}


int main6()
{
	int a = 10;
	int b = 20;

	swap(a, b);
	
	system("pause");

	return 0;
}