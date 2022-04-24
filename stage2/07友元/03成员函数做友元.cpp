#include<iostream>
using namespace std;

class Building;
class GoodGay {

public:
	GoodGay();

	void visit();	//让visit函数可以访问Building中的私有成员
	void visit2();	//不让visit2函数访问Building中的私有成员

	Building* building;

};

class Building {
	//Building类之外的 visit成员函数 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	friend void GoodGay::visit();

public:
	Building();

public:
	string m_settingroom;	//客厅

private:
	string m_bedroom;	//卧室

};

//类外实现成员函数
GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "类外成员函数visit 正在访问：" << building->m_settingroom << endl;
	//Building类之外的 visit成员函数 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	cout << "类外成员函数visit 正在访问：" << building->m_bedroom << endl;
}

void GoodGay::visit2() {
	cout << "类外成员函数visit2 正在访问：" << building->m_settingroom << endl;
	//cout << "类外成员函数visit2 正在访问：" << building->m_bedroom << endl;
}

Building::Building() {
	m_settingroom = "客厅";
	m_bedroom = "卧室";
}


void test01() {
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main() {

	test01();


	system("pause");
	return 0;
}