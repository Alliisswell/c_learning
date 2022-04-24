#include<iostream>

using namespace std;


/*
* 二维数组数组名的用途：
* 1、查看二维数组所占内存空间
* 2、获取二维数组首地址
* 
* //&为取址符，查看元素地址时需要添加取址符
* 
*/

int main7()
{
	//1、可以通过数组名统计整个数组占用内存大小
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "二维数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "二维数组第一行占用内存为：" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素占用内存为：" << sizeof(arr[0][0]) << endl;
	cout << "二维数组的行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组的列数为：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//2、可以通过数组名查看数组首地址
	cout << "二维数组首地址：" << (int)arr << endl;

	cout << "二维数组第一行地址：" << (int)arr[0] << endl;
	cout << "二维数组第二行地址：" << (int)arr[1] << endl;

	cout << "二维数组第一个元素地址：" << (int)&arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << (int)&arr[0][1] << endl;

	system("pause");

	return 0;
}

//> 总结1：二维数组名就是这个数组的首地址
//
//> 总结2：对二维数组名进行sizeof时，可以获取整个二维数组占用的内存空间大小