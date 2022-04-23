#include<iostream>

using namespace std;

int main7()
{
	//创建bool数据类型
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;

	//本质上 1代表真 0代表假

	flag = 1;
	cout << flag << endl;

	flag = 0;
	cout << flag << endl;

	flag = 10;  //非零都是真
	cout << flag << endl;

	//查看bool类型所占内存空间大小 1个字节
	cout << "bool类型所占内存空间为：" << sizeof(bool) << endl;

	system("pause");

	return 0;
}