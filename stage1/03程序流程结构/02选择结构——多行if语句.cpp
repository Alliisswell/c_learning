#include<iostream>

using namespace std;

int main2()
{
	//1、输入考试分数
	int score = 0;
	cout << "请输入一个人分数" << endl;
	cin >> score;

	//2、提示用户输入的分数
	cout << "您输入的的分数为：" << score << endl;

	//3、判断 如果大于600分，打印考上一本，否则打印未考上一本
	if (score > 600)//注意事项，if条件语句后面不要加分号
	{
		cout << "恭喜您考上了一本大学！" << endl;
	}
	else
	{
		cout << "恭喜您没有考上一本大学！" << endl;
	}
	system("pause");

	return 0;
}