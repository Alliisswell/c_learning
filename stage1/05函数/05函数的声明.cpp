#include<iostream>

using namespace std;

//函数的声明
//作用：告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
//函数的**声明可以多次**，但是函数的**定义只能有一次**

//提前告诉编译器被调用函数的存在，可以利用函数的声明
//声明可以写多次，但是函数定义只能写一次，但是没有必要写多次，写多次没有意义
int max(int a, int b);
int max(int a, int b);
int max(int a, int b);

int main5()
{
	int a = 10;
	int b = 20;

	cout << max(a, b) << endl;// max(a,b) 有参函数调用时，参数列表内不用再写数据类型

	system("pause");

	return 0;
}

//定义一个函数，实现两个整形数据进行比较，返回较大的值
int max(int a, int b)  //函数的定义如果放在主函数后边就需要提前声明函数
{
	return a > b ? a : b;
}

//下面是错的，定义只能写一次
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}