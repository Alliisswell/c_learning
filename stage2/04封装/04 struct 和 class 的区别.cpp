#include<iostream>

using namespace std;

//��C++�� struct �� class Ψһ����������� Ĭ�ϵķ���Ȩ�޲�ͬ
// struct Ĭ��Ȩ��Ϊ ���� public
// class Ĭ��Ȩ��Ϊ ˽�� private

struct C1 {
	int m_a = 0;	//Ĭ��Ȩ����	���� public
};

class C2 {
	int m_a = 0;	//Ĭ��Ȩ����	˽�� private
};


int main() {

	C1 c1;
	c1.m_a = 10;  //�� struct ���ǹ�����Ա��������Է���

	C2 c2;
	//c2.m_a = 10;	//�� class ����˽�г�Ա�����ⲻ���Է���


	system("pause");
	return 0;
}