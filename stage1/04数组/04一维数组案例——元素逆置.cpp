#include<iostream>

using namespace std;

void print(int arr[], int len ) {
	int start = 0;  //起始下标
	int end = sizeof(arr) / sizeof(arr[0]) - 1;  //结束下标
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout << "print函数中：" << endl;
	for (int j = 0; j < len; j++)
	{
		cout << arr[j] << "  ";
	}
	cout << endl;
}

int main()
{
	//1、创建数组
	int arr[6] = { 0,2,4,6,8,10 };
	cout << "逆置前main函数中：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << "  ";
	}
	
	//2、实现元素逆置
	//2.1记录起始下标位置
	//2.2记录结束下标位置
	//2.3起始下标于结束下标的元素互换
	//2.4起始位置++，结束位置--
	//2.5循环执行2.1-2.4操作，直到起始位置 >= 结束位置
	//int start = 0;  //起始下标
	//int end = sizeof(arr) / sizeof(arr[0]) - 1;  //结束下标
	//while (start < end)
	//{
	//	int temp = arr[start];  
	//	arr[start] = arr[end];
	//	arr[end] = temp;
	//	start++;
	//	end--;
	//}

	//3、打印逆置后的数组
	cout << "\n";
	cout << "输出元素逆置后的数组:" << endl;
	print(arr, 6);
	//for (int j = 0; j < 6; j++)
	//{
	//	cout << arr[j] << "  ";
	//}
	
	cout << "逆置后main函数中：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << "  ";
	}

	system("pause");

	return 0;
}