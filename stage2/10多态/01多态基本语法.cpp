#include<iostream>
using namespace std;

/*
多态分为两类：
* 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：

* 静态多态的函数地址早绑定  -  编译阶段确定函数地址
* 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
*/

class Animal {

public:
	virtual void speak() {  //虚函数
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	//重写：函数的 返回值类型 函数名 参数列表 要完全相同（有区别于 重载 ）
	virtual void speak() {	//子类重写函数时，virtual 可写可不写
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal {

public:
	virtual void speak() {
		cout << "小狗在说话" << endl;
	}
};


void doSpeak(Animal& animal) {	//Animal& animal = cat;
	animal.speak();
}

//执行说话的函数
//地址早绑定  在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
void test01() {
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main() {

	test01();

	system("pause");
	return 0;
}

//动态多态满条件
//1、有继承关系
//2、子类要重写父类的虚函数

//动态多态使用
//父类的指针或引用 指向子类对象

//重写：函数返回值类型  函数名 参数列表 完全一致称为重写

/*
#include<iostream>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/