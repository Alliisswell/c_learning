#include<iostream>

using namespace std;

//1��������Ϊ���ص�����
void func41(int& a) {
	cout << "func41(int& a) �ĵ��ã�" << endl;
}

void func41(const int& a) {
	cout << "func41(const int& a) �ĵ��ã�" << endl;
}
//2��������������Ĭ�ϲ���
void func42(int a, int b = 10) {
	cout << "func42(int a, int b = 10) �ĵ��ã�" << endl;
}

void func42(int a) {
	cout << "func42(int a) �ĵ��ã�" << endl;
}


int main4() {

	//int a = 10;
	//func41(a);

	//func41(10);

	//func42(10);	//��������������Ĭ�ϲ��������ֶ����ԣ��������������������
	func42(10, 20);	//��Ȼ��˵����ǿ��Եģ�����ֹ��һ������ȻҪ����

	system("pause");
	return 0;
}