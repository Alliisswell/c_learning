﻿#include<iostream>
using namespace std;

/*
*  对象的初始化和清理
*  生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用时候也会删除一些自己信息数据保证安全
*  C++中的面向对象来源于生活，每个对象也都会有初始设置以及 对象销毁前的清理数据的设置。

#### 构造函数和析构函数

对象的**初始化和清理**也是两个非常重要的安全问题

​	一个对象或者变量没有初始状态，对其使用后果是未知

​	同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

c++利用了  构造函数  和  析构函数  解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。

对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供构造和析构，编译器会提供

**编译器提供的构造函数和析构函数是空实现。**

* 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
* 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作。
*/

class Person {
public:
	//  构造函数  进行初始化操作
	//构造函数语法：类名(){}
	//1、没有返回值，不用写void
	//2、函数名与类名相同
	//3、构造函数可以有参数，可以发生重载
	//4、创建对象的时候，构造函数会自动调用，而且只调用一次
	Person() {
		cout << "Person 构造函数的调用" << endl;
	}

	//  析构函数  进行清理的操作
	//析构函数语法：~类名(){}
	//1、没有返回值，不用写void
	//2、函数名与类名相同，在类名前加“ ~ ”号
	//3、构造函数不可以有参数，不可以发生重载
	//4、对象在销毁前，会自动调用析构函数，而且只调用一次
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}
};

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01() {
	Person p;	//在栈上的数据，test01执行完毕后，释放这个对象，进而调用析构函数 
}

int main() {

	//test01();

	Person p;  //此处执行完之后如果不按任意键，p就不会被释放，也就不会调用析构函数，
			//只有按任意键，p才会被释放，进而调用析构函数，但是瞬间发生，肉眼在屏幕上看不到

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