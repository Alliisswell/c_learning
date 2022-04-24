#include<iostream>

using namespace std;

int main3()
{

	//1、创建5只小猪体重的数组
	int arr[5] = {100,200,1000,400,350};
	cout << "五只小猪体重分别是：" << endl;

	
	for (int j = 0; j < 5; j++)
	{
		cout << arr[j] << "  ";
	}
	cout << "\n";

	//2、从数组中找到最大值
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		//如果访问的数组中的元素比我认定的最大值还要大，更新最大值
		if (max<arr[i])
		{
			max = arr[i];
		}
	}

	//3、打印最大值
	cout<<"最重的小猪体重是：" << max << endl;

	system("pause");

	return 0;
}