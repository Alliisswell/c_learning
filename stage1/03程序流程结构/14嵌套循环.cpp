#include<iostream>

using namespace std;

int main14()
{
	//外层执行一次，内层执行一周
	//外层循环
	for (int i = 0; i < 10; i++)
	{
		//内层循环
		for (int j = 0; j < 10; j++)  //虽然有就近原则，但是为了阅读时候避免歧义，每层循环使用不同变量名
		{
			cout << "* ";
		}
		cout << endl;
	}



	system("pause");

	return 0;
}