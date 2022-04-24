#include<iostream>

using namespace std;

//函数常见样式
//1、无参无返	//无参数类型不可以创建变量,原因无法分配内存
//2、有参无返
//3、无参有返	//无参数类型不可以创建变量,原因无法分配内存
//4、有参有返

//1、无参无返
void test01()
{
	//无参数类型不可以创建变量,原因无法分配内存
	cout << "this is test01" << endl;
}

//2、有参无返
void test02(int a)
{
	cout << "this is test02 a = " << a << endl;
}

//3、无参有返
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4、有参有返
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}

int main4()
{
	//1、 无参无返函数调用
	test01();
	//2、 有参无返函数调用
	test02(100);
	//3、无参有返函数调用
	int num1 = test03();
	cout << "num1=" << num1 << endl;
	//4、有参有返函数调用
	int num2 = test04(100,200);
	cout << "num2=" << num2<<endl;
	system("pause");

	return 0;
}