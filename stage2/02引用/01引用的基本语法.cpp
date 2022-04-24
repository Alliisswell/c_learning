#include<iostream>

using namespace std;

int main1() {

	//引用的作用：给变量起别名
	//引用的语法：数据类型& 别名 = 原名
	
	int a = 10;
	//创建引用
	int& b = a;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	b = 100;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;




	system("pause");
	return 0;
}


/*
#include<iostream>

using namespace std;

int main() {


	system("pause");
	return 0;
}
*/