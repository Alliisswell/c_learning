#include<iostream>

using namespace std;

/*
**嵌套if语句**：在if语句中，可以嵌套使用if语句，达到更精确的条件判断

案例需求：

* 提示用户输入一个高考考试分数，根据分数做如下判断
* 分数如果大于600分视为考上一本，大于500分考上二本，大于400考上三本，其余视为未考上本科；
* 在一本分数中，如果大于700分，考入北大，大于650分，考入清华，大于600考入人大。
*/

int main4()
{

	int score = 0;
	cout << "请输入一个人分数" << endl;
	cin >> score;

	cout << "您输入的的分数为：" << score << endl;

	if (score > 600)//注意事项，if条件语句后面不要加分号
	{
		cout << "恭喜您考上了一本大学！" << endl;

		if (score>700)
		{
			cout << "您能考入北京大学！" << endl;
		}

		else if (score>650)
		{
			cout << "您能考入清华大学！" << endl;
		}

		else
		{
			cout << "您能考入中国人民大学！" << endl;
		}
	}

	else if (score > 500)//第二个判断条件
	{
		cout << "恭喜您考上了二本大学！" << endl;
	}

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