#include<iostream>

using namespace std;

int main2()
{
	//整型：short(2)	int(4)	  long(4)    long long(8)		
	//可以利用sizeof求出数据类型占用占用内存大小
	//语法：sizeof(数据类型/变量)
	
	short num1 = 10;
	cout << "short占用内存空间为： " <<sizeof(short)<< endl;

	long long num2 = 10;
	cout << "long long占用内存空间为： " << sizeof(num2) << endl;

	//整型数据大小比较：
	//short < int <= long <= long long 

	system("pause");

	return 0;
}