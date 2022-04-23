#include<iostream>

using namespace std;

int main11()
{
	//1、将所有的三位数进行输(100-999)
	int num = 100;
	do
	{
		//2、在所有三位数中找出水仙花数
		int a = 0;//个位
		int b = 0;//十位
		int c = 0;//百位

		//获取数字的各位数字，使用整除和取模运算
		a = num % 10;//直接取模于10，获取个位
		b = num / 10 % 10;//先整除10，去掉个位，再取模于10，获取十位
		c = num / 100;//直接整除100，去掉个位和十位，获取百位

		if (a*a*a+b*b*b+c*c*c==num)//如果是水仙花数才打印
		{
			cout << num << endl;
		}
		//下边代码可以运行但是不符合题意，数字的自加不需要进行条件判断
		//else 
		//{
		//	num++;
		//}
		num++;
	} 
	while (num<1000);

	system("pause");

	return 0;
}