#include<iostream>

using namespace std;

//ֵ���ݣ���νֵ���ݣ����Ǻ�������ʱ��ʵ�ν���ֵ������β�

//* ֵ����ʱ�� == ����βη�����������Ӱ��ʵ�� ==


//���庯����ʵ���������ֽ��н���
//�����������Ҫ����ֵ��������ʱ�����дvoid

void swap3(int num1, int num2)
{
	cout << "����ǰ��" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "������" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return;//����Ҫ����ֵ��ʱ��ֻ��Ҫд  return; ����ʲô����д
}

int main3()
{

	int a = 10;
	int b = 20;

	cout << "mian�е� a = " << a << endl;
	cout << "mian�е� b = " << b << endl;

	//��������ֵ���ݵ�ʱ�򣬺������βη����κεĸı䣬������Ӱ��ʵ��

	swap3(a,b);//ֵ���ݣ��βη����ı�

	//�����ʵ�Σ����Կ���ʵ�β�û���ܵ�Ӱ��
	cout << "mian�е� a = " << a << endl;
	cout << "mian�е� b = " << b << endl;

	system("pause");

	return 0;
}

//�ܽ᣺ֵ����ʱ���β�ʱ���Σ��ı䣩����ʵ�ε�