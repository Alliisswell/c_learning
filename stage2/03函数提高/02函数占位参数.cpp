#include<iostream>

using namespace std;

//�﷨������ֵ���� ������(��������) {}

//���ֽ׶κ�����ռλ�����������岻�����ǻ��ò��������Ǻ���Ŀγ��л��õ��ü���

void func21(int a, int) {
	cout << "this is func21" << endl;
}

void func22(int a, int = 10) {
	cout << "this is func22" << endl;
}
int main2() {

	func21(10, 10);	//C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��

	func22(10);	//ռλ������������Ĭ��ֵ�����ҵ�ռλ��������Ĭ��ֵʱ�����ú���ʱ���Բ������λ��

	system("pause");
	return 0;
}