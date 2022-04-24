#include<iostream>
using namespace std;

/*
在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为  ==friend==

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元
*/

class Building {
	//goodGay全局函数 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	friend void goodGay(Building& building);

public:
	Building() {
		m_settingroom = "客厅";
		m_bedroom = "卧室";
	}

public:
	string m_settingroom;	//客厅

private:
	string m_bedroom;	//卧室
};

void goodGay(Building& building) {
	cout << "好基友全局函数 正在访问：" << building.m_settingroom << endl;
	//goodGay全局函数 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	cout << "好基友全局函数 正在访问：" << building.m_bedroom << endl;

}

void test01() {
	Building building;
	goodGay(building);
}

int main() {

	test01();


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