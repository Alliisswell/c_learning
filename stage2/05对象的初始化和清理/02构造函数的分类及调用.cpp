#include<iostream>
using namespace std;

/*
##构造函数的分类及调用

两种分类方式：

​	按参数分为： 无参构造（默认构造）和有参构造

​	按类型分为： 普通构造和拷贝构造

三种调用方式：

​	括号法（常用）

​	显示法

​	隐式转换法
*/

//1、构造函数的分类及调用
//分类
//按照参数分类  无参构造（默认构造）和  有参构造
//按照类型分类  普通构造  和  拷贝构造
class Person {
public:
	//构造函数
	Person() {
		cout << "Person 默认构造函数的调用" << endl;
	}
	Person(int a) {
		age = a;
		cout << "Person 有参构造函数的调用" << endl;
	}
	//拷贝构造函数
	Person(const Person& p){  //将参数以  常量引用  的方式传进来，初步理解为：1、节省内存空间，2、防止误操作，3、简化语法（相对用指针来讲）
		//将传入的人身上的属性，拷贝到我身上
		age = p.age;
		cout << "Person 拷贝构造函数的调用" << endl;
	}
	
	//析构函数
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	int age=0;	//年龄
};

void test01() {
	
	//括号法（我喜欢用！）
	//Person p1;	//默认（无参）构造函数的调用
	//Person p2(10);	//有参构造函数的调用
	//Person p3(p2);	//拷贝构造函数的调用
	
	//注意事项1：
	//调用默认（无参）构造函数的时候，不要加（）
	//因为下面这行代码，编译器会认为这是一个函数的声明，因为在一个函数体内部，声明另一个函数是合法的
	// 
	//Person p1();

	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p3.age << endl;

	//显示法
	//Person p1;
	//Person p2 = Person(10);
	//Person p3 = Person(p2);

	//Person(10);	//匿名对象  特点：当前行执行结束后，系统会立刻回收匿名对象
	//cout << "aaa" << endl;

	//注意事项2：
	//不要利用拷贝构造函数 初始化匿名对象 编译器会认为 Person(p2); === Person p3;(对象声明)，报错：重定义
	//Person(p3);
	
	//隐式转换法
	Person p4 = 10;	//有参构造  相当于 Person p4 = Person(10);
	Person p5 = p4;	//拷贝构造  相当于 Person p5 = Person(p4);

}

//调用
int main() {

	test01();

	system("pause");
	return 0;
}