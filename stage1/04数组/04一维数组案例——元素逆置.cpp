#include<iostream>

using namespace std;

void print(int arr[], int len ) {
	int start = 0;  //��ʼ�±�
	int end = sizeof(arr) / sizeof(arr[0]) - 1;  //�����±�
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout << "print�����У�" << endl;
	for (int j = 0; j < len; j++)
	{
		cout << arr[j] << "  ";
	}
	cout << endl;
}

int main()
{
	//1����������
	int arr[6] = { 0,2,4,6,8,10 };
	cout << "����ǰmain�����У�" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << "  ";
	}
	
	//2��ʵ��Ԫ������
	//2.1��¼��ʼ�±�λ��
	//2.2��¼�����±�λ��
	//2.3��ʼ�±��ڽ����±��Ԫ�ػ���
	//2.4��ʼλ��++������λ��--
	//2.5ѭ��ִ��2.1-2.4������ֱ����ʼλ�� >= ����λ��
	//int start = 0;  //��ʼ�±�
	//int end = sizeof(arr) / sizeof(arr[0]) - 1;  //�����±�
	//while (start < end)
	//{
	//	int temp = arr[start];  
	//	arr[start] = arr[end];
	//	arr[end] = temp;
	//	start++;
	//	end--;
	//}

	//3����ӡ���ú������
	cout << "\n";
	cout << "���Ԫ�����ú������:" << endl;
	print(arr, 6);
	//for (int j = 0; j < 6; j++)
	//{
	//	cout << arr[j] << "  ";
	//}
	
	cout << "���ú�main�����У�" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << "  ";
	}

	system("pause");

	return 0;
}