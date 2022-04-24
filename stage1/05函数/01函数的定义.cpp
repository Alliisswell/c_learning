#include<iostream>

using namespace std;


//作用：将一段经常使用的代码封装起来，减少重复代码

//一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。
	
/*语法：
		
	返回值类型 函数名 （参数列表）
	{

		函数体语句

		return表达式

	}
*/
	
int add1(int num1, int num2)
{
	int sum = num1 + num2;

	return sum;
	
}

//*返回值类型 ：一个函数可以返回一个值。在函数定义中
//* 函数名：给函数起个名称
//* 参数列表：使用该函数时，传入的数据
//* 函数体语句：花括号内的代码，函数内需要执行的语句
//* return表达式： 和返回值类型挂钩，函数执行完后，返回相应的数据

int main1()
{
	
	system("pause");

	return 0;
}

/*

#include<iostream>

using namespace std;

int main()
{


	system("pause");

	return 0;
}

*/