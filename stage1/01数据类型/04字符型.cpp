#include<iostream>

using namespace std;

int main4()
{
	//�ַ��ͱ���������ʽ
	char ch = 'a';
	cout << ch << endl;
	
	//�ַ��ͱ�����ռ�ڴ��С
	cout << "char��ռ�ڴ�ռ��СΪ��" << sizeof(char) << endl;  //C��C++���ַ��ͱ���ֻռ��1���ֽ�

	//�ַ��ͱ�����������
	//char ch2 = "a";
	//char ch2 = 'abcdef';

	//�ַ��ͱ��������ǰ��ַ�����ŵ��ڴ��д洢�����ǽ���Ӧ��ASCII������뵽�洢��Ԫ
	//�ַ��ͱ�����ӦASCII���룺
	//a---97
	//A---65
	cout << (int)ch << endl;//ǿ����ʮ���������ch



	system("pause");

	return 0;


}