#include<iostream>

using namespace std;

//**���ã�** ��������ʱ�������������õļ������β�����ʵ��
//
//**�ŵ㣺** ���Լ�ָ���޸�ʵ��

//���ӣ���������

//1��ֵ����
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "swap01a= " << a << endl;
	cout << "swap01b= " << b << endl;
}
//2����ַ����
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	cout << "swap02a= " << *a << endl;
	cout << "swap02b= " << *b << endl;

}
//3�����ô���
void mySwap03(int& a, int& b) {	//�����β�a,b��ʵ��a,b�ı���
	int temp = a;
	a = b;
	b = temp;

	cout << "swap03a= " << a << endl;
	cout << "swap03b= " << b << endl;
}

int main3() {

	int a = 10;
	int b = 20;

	//mySwap01(a, b);	//ֵ���ݣ��ββ���������ʵ��
	//mySwap02(&a, &b);	//��ַ���ݣ��βο�������ʵ��
	mySwap03(a, b);	//���ô��ݣ��β�Ҳ��������ʵ��


	cout << "a= " << a << endl;
	cout << "b= " << b << endl;


	system("pause");
	return 0;
}

//�ܽ᣺ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������