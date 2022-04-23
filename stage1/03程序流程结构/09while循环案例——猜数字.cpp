#include<iostream>

#include<ctime>//time系统时间头文件包含

using namespace std;

int main9()
{
	//添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));

	//1、系统生成随机数1-100
	int num = rand() % 100 + 1;//rand()%100生成0-99随机数
	//cout << num << endl;
	
	//2、玩家进行猜测
	int val = 0;
	cout << "请输入您的猜测：" << endl;
	while (1)
	{
		cin >> val;

		//3、判断玩家的猜测
		//猜错	提示猜测的结果是过大或过小，重新返回第二步
		if (val > num)
		{
			cout << "猜测过大" << endl;
		}
		else if (val<num)
		{
			cout << "猜测过小" << endl;
		}
		//猜对	退出游戏
		else
		{
			cout << "恭喜您猜对了！" << endl;
			break;//可以利用该关键字来退出当前循环 
		}
	}
	
	system("pause");

	return 0;
}