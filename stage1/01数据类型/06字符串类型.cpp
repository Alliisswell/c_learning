#include<iostream>
#include<string>//用C++风格字符串的时候，要包含这个头文件
using namespace std;

int main6()
{
	//1.C风格字符串
	//注意事项	变量名后边加[]
	//注意事项2	等号后面要用双引号将字符串包含起来
	char str[] = "hello world";
	cout << str << endl;

	//2.C++风格字符串
	//注意事项	要包含一个头文件
	string str2 = "hello world";
	cout << str2 << endl;

	system("pause");

	return 0;
}