#include<iostream>

using namespace std;

//�����������ķ���ֵ

//1����Ҫ���ؾֲ�����������
int& test01() {
	int a = 10;	//�ֲ���������������е� ջ��
	return a;
}

//2���������ÿ�����Ϊ��ֵ
int& test02() {
	static int a = 10;	//��̬�����������ȫ������ȫ�����ϵ������ڳ���������ɲ���ϵͳ�ͷ�
	return a;  //�����õķ�ʽ����ȫ�����ı������൱������һ�����ã��������Ǻ����� === int& test02() = a;
}

int main4() {

	int& ref1 = test01();

	cout << "ref1= " << ref1 << endl;	//������Ϊa���ڴ��Ѿ��ͷ�
	
	int& ref2 = test02();	//test02���Ǿ�̬����a�ı�����Ȼ���ֱ�ref2������

	cout << "ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;

	test02() = 1000;	//��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ����ֵ���ǵȺ���ߵĶ��������Ǹ�ֵ����

	cout << "ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;



	system("pause");
	return 0;
}