#include<iostream>

using namespace std;

//���õı��ʣ����õı�����c++���ڲ�ʵ�� �� һ��ָ�볣��

int main5() {
	
	int a = 10;

	int& ref = a;	//�ڲ�����ref������,�Զ�ת��Ϊ int* const ref = &a; ��ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ��ģ�
	ref = 20;	//�ڲ�����ref�����ã��Զ�������ת��Ϊ *ref = 20;

	cout << "a= " << a << endl;
	cout << "ref= " << ref << endl;

	system("pause");
	return 0;
}

//���ۣ�C++�Ƽ������ü�������Ϊ�﷨���㣬���ñ�����ָ�볣�����������е�ָ�����������������������