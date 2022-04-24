#include<iostream>
using namespace std;

class AbstractDrinking {

public:
	//煮水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入辅料
	virtual void PutSomething() = 0;

	//制作饮品（公共接口，一个接口多种形态）
	void makeDrinking() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡类
class Coffee:public AbstractDrinking {

public:
	//煮水
	virtual void Boil() {
		cout << "煮雪山水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}

	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入咖啡杯" << endl;
	}

	//加入辅料
	virtual void PutSomething() {
		cout << "加入糖和牛奶" << endl;
	}
};

//制作茶叶类
class Tea :public AbstractDrinking {

public:
	//煮水
	virtual void Boil() {
		cout << "煮深井水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	}

	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入紫砂壶" << endl;
	}

	//加入辅料
	virtual void PutSomething() {
		cout << "加入枸杞人参藏红花" << endl;
	}
};

void doWork(AbstractDrinking* abs) {
	abs->makeDrinking();
	delete abs;
}

void test01() {
	//制作咖啡
	doWork(new Coffee);
	cout << "----------------------" << endl;
	//制作茶水
	doWork(new Tea);

}


int main() {

	test01();

	system("pause");
	return 0;
}