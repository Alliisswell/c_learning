#include<iostream>

using namespace std;

int main()
{
	//1.������ float 4���ֽڣ�7λ��Ч���֣�
	//2.˫���� double 8���ֽڣ�15-16λ��Ч���֣�
	

	float f1 = 3.1415926f;	//Ĭ�������ϵͳ��Ϊʵ������λ˫���ȣ�double������������ֵ��߼�f����ʡȥ��ϵͳ���Զ�ת������
	cout << "f1= " << f1 << endl;	//Ĭ������£����һ��С��������ʾ����λ��Ч���֣�
									

	double d1 = 3.1415926;
	cout << "d1= " << d1 << endl;  //���� ����˫���� ��ֻ�����λ���֣������Ҫ�������λ����Ҫ���û����������ݳ���


	//ͳ��float��doubleռ���ڴ�ռ�
	cout << "floatռ���ڴ�ռ�Ϊ��" << sizeof(float) << endl;  //4�ֽ�
	cout << "doubleռ���ڴ�ռ�Ϊ��" << sizeof(double) << endl;  //8�ֽ�  

	//��ѧ������
	float f2 = 3e2;//3 * 10 ^ 2
	cout << "f2=" << f2 << endl;
	float f3 = 3e-2;//3 * 0.1 ^ 2
	cout << "f3=" << f3 << endl;

	system("pause");

	return 0;
}