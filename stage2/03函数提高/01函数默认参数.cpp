#include<iostream>

using namespace std;

//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ�ġ�

//�﷨������ֵ����  ������ ������ = Ĭ��ֵ��{}

//��������Լ��������ݣ������Լ������ݣ����û�У���ô����Ĭ��ֵ
int func11(int a, int b = 20, int c = 30) {
	return a + b + c;
}



//ע������
//1�����ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴������Ҷ�������Ĭ��ֵ
//int func2(int a, int b = 20, int c) {
//	return a + b + c;
//}

//2���������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ����Ĭ�ϲ���
int func12(int a = 10, int b = 10);

int func12(int a, int b) {
	return a + b;
}

int main1() {

	cout << func11(10, 30) << endl;	//10��ֵ��a��30��ֵ������cʹ��Ĭ��ֵ
	cout << func12(10, 10) << endl;



	system("pause");
	return 0;
}

/*
#include<iostream>

using namespace std;

int main() {



	system("pause");
	return 0;
}
*/