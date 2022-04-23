#include<iostream>

using namespace std;

/*
**作用：可以无条件跳转语句

**语法：goto 标记;

**解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
*/

int main18()
{
	cout << "1.xxxx" << endl;
	cout << "2.xxxx" << endl;
	goto FLAG;

	cout << "3.xxxx" << endl;
	cout << "4.xxxx" << endl;

	FLAG:
	cout << "5.xxxx" << endl;
	
	
	
	system("pause");

	return 0;

}

//注意：在程序中不建议使用goto语句，以免造成程序流程混乱
