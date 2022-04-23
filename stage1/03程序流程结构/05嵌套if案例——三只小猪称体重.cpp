#include<iostream>

using namespace std;
/*
**练习案例：** 三只小猪称体重

有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
*/
int main5()
{
	//三只小猪称体重
	int a, b, c;
	cout << "请依次输入三只小猪的体重" << endl;
	cin >> a >> b >> c;

	cout << "小猪a的体重为：" << a << endl;
	cout << "小猪b的体重为：" << b << endl;
	cout << "小猪c的体重为：" << c << endl;

	if (a>b)  //a>b
	{
		if (a>c)  //a>b,a>c
		{
			cout << "小猪a最重" << endl;
		}
		else  //b<a<c
		{
			cout << "小猪c最重" << endl;
		}
	}
	else //b>a
	{
		if (b>c)  //b>a,b>c
		{
			cout << "小猪b最重" << endl;
		}
		else  //a<b<c
		{
			cout << "小猪c最重" << endl;
		}
	}
	system("pause");

	return 0;
}