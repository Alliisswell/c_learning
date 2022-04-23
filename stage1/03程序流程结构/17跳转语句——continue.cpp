#include<iostream>

using namespace std;

//continue
//**作用：**在==循环语句==中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

int main()
{
	for (int i = 0;i<=100;i++)
	{
		//如果是奇数输出，偶数不输出
		if (i % 2 == 0)
		{
			continue;//可以筛选条件，执行到此就不再向下执行，执行下一次循环
		}

		cout << i << endl;
	}
	system("pause");

	return 0;
}

//注意：continue并没有使整个循环终止，而break会跳出循环

