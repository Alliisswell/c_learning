#include<iostream>

using namespace std;

int main3()
{

	//1������5ֻС�����ص�����
	int arr[5] = {100,200,1000,400,350};
	cout << "��ֻС�����طֱ��ǣ�" << endl;

	
	for (int j = 0; j < 5; j++)
	{
		cout << arr[j] << "  ";
	}
	cout << "\n";

	//2�����������ҵ����ֵ
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		//������ʵ������е�Ԫ�ر����϶������ֵ��Ҫ�󣬸������ֵ
		if (max<arr[i])
		{
			max = arr[i];
		}
	}

	//3����ӡ���ֵ
	cout<<"���ص�С�������ǣ�" << max << endl;

	system("pause");

	return 0;
}