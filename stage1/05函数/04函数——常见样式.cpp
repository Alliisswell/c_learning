#include<iostream>

using namespace std;

//����������ʽ
//1���޲��޷�	//�޲������Ͳ����Դ�������,ԭ���޷������ڴ�
//2���в��޷�
//3���޲��з�	//�޲������Ͳ����Դ�������,ԭ���޷������ڴ�
//4���в��з�

//1���޲��޷�
void test01()
{
	//�޲������Ͳ����Դ�������,ԭ���޷������ڴ�
	cout << "this is test01" << endl;
}

//2���в��޷�
void test02(int a)
{
	cout << "this is test02 a = " << a << endl;
}

//3���޲��з�
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4���в��з�
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}

int main4()
{
	//1�� �޲��޷���������
	test01();
	//2�� �в��޷���������
	test02(100);
	//3���޲��з���������
	int num1 = test03();
	cout << "num1=" << num1 << endl;
	//4���в��з���������
	int num2 = test04(100,200);
	cout << "num2=" << num2<<endl;
	system("pause");

	return 0;
}