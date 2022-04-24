#include<iostream>

using namespace std;

//**作用：** 利用指针作函数参数，可以修改实参的值（普通的函数参数，即形参，是不能修饰实参的）

//实现两个数字进行交换
void swap01(int c, int d) {
	int temp = c;
	c = d;
	d = temp;

	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}
void swap02(int* p1,int* p2) {
	int temp = *p1;//解引用后的操作对象就是指向的变量
	*p1 = *p2;
	*p2 = temp;
}
int main7()
{

	int a = 10;
	int b = 20;

	//1、值传递
	swap01(a, b);//值传递，不改变实参

	//2、地址传递
	swap02(&a,&b);//地址传递，可以改变实参

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	system("pause");

	return 0;
}

//总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递