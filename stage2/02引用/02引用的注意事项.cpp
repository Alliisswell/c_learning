#include<iostream>

using namespace std;

int main2() {
	
	//1�����ñ����ʼ��
	int a = 10;
	//int& b;	//���󣬱���Ҫ��ʼ��
	int& b = a;
	int& d = b;  //���ÿ��Զ��һ�����ǿ����кܶ��������b��d����a�ı���,���ұ���b������Ϊԭ���ٴα�����

	//2�������ڳ�ʼ���󣬲����Ըı䣨�����Ը��������ö���
	int c = 20;
	b = c;	//���Ǹ�ֵ�������ǺϷ���
	//int& b = c;	//����b ���� a ��,�����Ը��ı����ö���

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;

	system("pause");
	return 0;
}