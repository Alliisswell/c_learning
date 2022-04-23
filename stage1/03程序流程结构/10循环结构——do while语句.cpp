#include<iostream>

using namespace std;

/*
**作用：** 满足循环条件，执行循环语句

**语法：** do{ 循环语句 } while(循环条件);

**注意：**与while的区别在于==do...while会先执行一次循环语句==，再判断循环条件
*/

int main10()
{
	//在屏幕中输出0到9这10个数字

	int num = 0;

	do
	{
		cout << num << endl;
		num++;

	} 
	while (num<10);

	system("pause");

	return 0;
}