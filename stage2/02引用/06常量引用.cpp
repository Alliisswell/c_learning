#include<iostream>

using namespace std;

//��������
//���ã�����������Ҫ���������βΣ���ֹ�����
//ʹ�ó������ں����β��б��У����Լ� const �����βΣ���ֹ�βθı�ʵ��

void showValue(const int& val) {
	//val = 1000;
	cout << "val= " << val << endl;
}

int main6() {

	//int a = 10;
		
	//int& ref = 10;	//�������ñ�������һ��Ϸ����ڴ棬����ջ����������ڴ棬�� 10 �ǳ���...
	//int& ref = a;	//���ǺϷ��ģ��ֲ����� a ��ջ��
	//const int& ref = 10;	//����const֮�󣬱������������޸� int temp = 10; const int& ref = temp;
	//ref = 20;	//����const֮���Ϊֻ�����������޸�

	int a = 100;
	showValue(a);
	cout << "a= " << a << endl;

	system("pause");
	return 0;
}