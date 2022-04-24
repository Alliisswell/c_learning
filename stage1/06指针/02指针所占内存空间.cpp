#include<iostream>

using namespace std;

int main2()
{
	//提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？

	cout << "sizeof(int*)= " << sizeof(int*) << endl;
	cout << "sizeof(double*)= " << sizeof(double*) << endl;
	cout << "sizeof(float*)= " << sizeof(float*) << endl;
	cout << "sizeof(char*)= " << sizeof(char*) << endl;

	//总结：所有指针类型在32位操作系统下是4个字节,在64位操作系统下是8个字节
	
	system("pause");

	return 0;
}