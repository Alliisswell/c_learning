#include<iostream>

using namespace std;

//1、引用作为重载的条件
void func41(int& a) {
	cout << "func41(int& a) 的调用！" << endl;
}

void func41(const int& a) {
	cout << "func41(const int& a) 的调用！" << endl;
}
//2、函数重载碰到默认参数
void func42(int a, int b = 10) {
	cout << "func42(int a, int b = 10) 的调用！" << endl;
}

void func42(int a) {
	cout << "func42(int a) 的调用！" << endl;
}


int main4() {

	//int a = 10;
	//func41(a);

	//func41(10);

	//func42(10);	//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
	func42(10, 20);	//当然如此调用是可以的，但防止万一出错，仍然要避免

	system("pause");
	return 0;
}