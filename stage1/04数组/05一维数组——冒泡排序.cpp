#include<iostream>

using namespace std;

//冒泡排序作用：最常用的排序算法，对数组内元素进行排序
//1. 从第一个元素开始，比较相邻的元素，如果第一个比第二个大，就交换他们两个。
//2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
//3. 重复以上的步骤，每次比较次数 - 1，直到不需要比较

int main5()
{
	//利用冒泡排序实现升序序列
	int arr[9] = {4,2,8,0,5,7,1,3,9};

	cout << "排序前：" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//开始冒泡排序
	//总共排序轮数 = 元素个数 - 1
	for (int i = 0; i < 9-1; i++)  //i为排序轮数
	{
		//内层循环对比次数 = 总共排序轮数 - 当前轮数 = 元素个数 - 1 - 当前轮数

		for (int j = 0; j < 9-1-i; j++)  //内层循环次数
		{
			//如果第一个元素比第二个元素大，交换两个元素
			if (arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//排序后输出结果
	cout << "排序后：" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;



	system("pause");

	return 0;
}