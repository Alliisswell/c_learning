#include<iostream>
using namespace std;


class Building;
class GoodGay {

public:
	GoodGay();

	void visit();	//参观函数  访问Building中的属性
	
	Building* building;
};

class Building {
	//GoodGay类 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	friend class GoodGay;

public:
	Building();

public:
	string m_settingroom;	//客厅

private:
	string m_bedroom;	//卧室
};

//类外写成员函数
GoodGay::GoodGay() {
	
	//创建建筑物对象
	building = new Building;
}

void GoodGay::visit() {
	cout << "好基友类 正在访问：" << building->m_settingroom << endl;
	//GoodGay类 是 Building类 的好朋友，可以访问 Building类 中的私有成员
	cout << "好基友类 正在访问：" << building->m_bedroom << endl;
}

Building::Building() {
	m_settingroom = "客厅";
	m_bedroom = "卧室";
}

void test01() {
	GoodGay gg;
	gg.visit();
}

int main() {

	test01();


	system("pause");
	return 0;
}