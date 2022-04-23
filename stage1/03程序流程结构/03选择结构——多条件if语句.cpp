#include<iostream>

using namespace std;

int main3()
{
	//1、输入考试分数
	int score = 0;
	cout << "请输入一个人分数" << endl;
	cin >> score;

	//2、提示用户输入的分数
	cout << "您输入的的分数为：" << score << endl;

	//3、判断是否考上一本 
	if (score > 600)//注意事项，if条件语句后面不要加分号
	{
		cout << "恭喜您考上了一本大学！" << endl;
	}
	//判断是否考上二本
	else if (score> 500)//第二个判断条件
	{
		cout << "恭喜您考上了二本大学！" << endl;
	}
	//判断是否考上三本
	else if (score > 400)//第三个判断条件
	{
		cout << "恭喜您考上了三本大学！" << endl;
	}
	else
	{
		cout << "很遗憾您没有考上本科！" << endl;
	}

	system("pause");

	return 0;
}