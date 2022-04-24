#include<iostream>
using namespace std;

//函数调用运算符() 也可以重载
//由于重载后使用的方式非常像函数的调用，因此称为仿函数
//仿函数没有固定写法，非常灵活

class MyPrint {

public:
	//重载函数调用运算符
	void operator()(string test) {
		cout << test << endl;
	}

};

void MyPrint02(string test) {
	cout << test << endl;
}

void test01() {
	MyPrint myprint;

	myprint("hellow world");	//由于使用起来非常类似于函数调用，因此称为仿函数

	MyPrint02("hellow world");	//这里只是简单的调用函数，而没有重载函数调用运算符
}

//仿函数没有固定写法，非常灵活
//创建加法类
class MyAdd {

public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}

};

void test02() {
	MyAdd myadd;
	int ret = myadd(100,100);
	cout << "ret = " << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;  // MyAdd() 就是一个匿名对象，语法：类() ，特点是当前行代码运行完毕之后立即被释放
	//注意：匿名函数对象 和 匿名对象 是有所区别的
}


int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}