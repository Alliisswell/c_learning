#include<iostream>
#include<string>

using namespace std;

//二位数组案例——考试成绩统计

int main8()
{
	
	//1、创建二维数组
	int score[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	string name[] = {"张三","李四","王五"};

	cout << "三位同学成绩如下：" << endl;

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;//定义分数综合变量
		
		cout << name[i] << "各科成绩为：";

		for (int j = 0; j < 3; j++)
		{
			sum += score[i][j];  //sum = sum + score[i][j];
			
			cout << score[i][j] << " ";
		}
		
		cout << endl;

		cout <<"总成绩为："<<sum << endl;
	}


	system("pause");

	return 0;
}

