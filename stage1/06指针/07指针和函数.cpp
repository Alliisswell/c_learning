#include<iostream>

using namespace std;

//**���ã�** ����ָ�������������������޸�ʵ�ε�ֵ����ͨ�ĺ������������βΣ��ǲ�������ʵ�εģ�

//ʵ���������ֽ��н���
void swap01(int c, int d) {
	int temp = c;
	c = d;
	d = temp;

	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}
void swap02(int* p1,int* p2) {
	int temp = *p1;//�����ú�Ĳ����������ָ��ı���
	*p1 = *p2;
	*p2 = temp;
}
int main7()
{

	int a = 10;
	int b = 20;

	//1��ֵ����
	swap01(a, b);//ֵ���ݣ����ı�ʵ��

	//2����ַ����
	swap02(&a,&b);//��ַ���ݣ����Ըı�ʵ��

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	system("pause");

	return 0;
}

//�ܽ᣺��������޸�ʵ�Σ�����ֵ���ݣ�������޸�ʵ�Σ����õ�ַ����