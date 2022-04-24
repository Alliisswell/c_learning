#include<iostream>
#include"swap.h"
using namespace std;


/*
### 6.7 函数的分文件编写

**作用：**让代码结构更加清晰

函数分文件编写一般有4个步骤

1. 创建后缀名为.h的头文件
2. 创建后缀名为.cpp的源文件
3. 在头文件中写函数的声明
4. 在源文件中写函数的定义

*/



//实现两个数字交换的函数

////函数的声明
//void swap(int a,int b);
////函数的定义
//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//}


int main6()
{
	int a = 10;
	int b = 20;

	swap(a, b);
	
	system("pause");

	return 0;
}