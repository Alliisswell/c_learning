#include<iostream>

using namespace std;

int main13()
{
	//1、先输出1-100
	for (int i = 0; i <=100; i++)
	{
		//2、从这100个数字当中找到特殊数字，打印“敲桌子”
		//如果是7的倍数（取模于7结果为0）、个位有7、十位有7，打印“敲桌子”
		

		if (i%7==0||i%10==7||i/10==7)//如果是特殊数字，打印敲桌子
		{
			cout << "敲桌子" << endl;
		}
		else//如果不是特殊数字，才打印数字
		{
			cout << i << endl;
		}
	}
	

	system("pause");

	return 0;
}