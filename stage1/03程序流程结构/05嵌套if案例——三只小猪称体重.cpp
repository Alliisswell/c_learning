#include<iostream>

using namespace std;
/*
**��ϰ������** ��ֻС�������

����ֻС��ABC����ֱ�������ֻС������أ������ж���ֻС�����أ�
*/
int main5()
{
	//��ֻС�������
	int a, b, c;
	cout << "������������ֻС�������" << endl;
	cin >> a >> b >> c;

	cout << "С��a������Ϊ��" << a << endl;
	cout << "С��b������Ϊ��" << b << endl;
	cout << "С��c������Ϊ��" << c << endl;

	if (a>b)  //a>b
	{
		if (a>c)  //a>b,a>c
		{
			cout << "С��a����" << endl;
		}
		else  //b<a<c
		{
			cout << "С��c����" << endl;
		}
	}
	else //b>a
	{
		if (b>c)  //b>a,b>c
		{
			cout << "С��b����" << endl;
		}
		else  //a<b<c
		{
			cout << "С��c����" << endl;
		}
	}
	system("pause");

	return 0;
}