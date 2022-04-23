#include<iostream>

using namespace std;

//经过分析
//列数*行数=计算结果
//每一行中，列数<=当前行数

int main15()
{
	//外层执行一次，内层执行一周
	
	//打印行数
	for (int i = 1; i <=9; i++)
	{
		//cout << i << endl;
		
		//打印列数
		for (int j = 1; j <=i; j++)  //实现 列数<=当前行数
		{
			cout << j << "*" << i << "=" << j * i <<"\t";//"\t"水平制表符，可以让每列输出的数据左对齐
		}
		cout << "\n";//等价于 cout << '\n'; 或 cout << endl;
		
		cout << endl;
	}
	


	system("pause");

	return 0;
}