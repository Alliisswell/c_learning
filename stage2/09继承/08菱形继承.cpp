#include<iostream>
using namespace std;

class Animal {	//动物类

public:
	int m_a = 0;
};

//利用虚继承  解决菱形继承的问题
//在继承之前加上关键字 virtual 变为虚继承
//Animal类 称为 虚基类
class Sheep :virtual public Animal {	//羊类
};

class Tuo :virtual public Animal {	//驼类
};

class SheepTuo :public Sheep, public Tuo {	//羊驼类


};

void test01() {
	SheepTuo st;
	st.Sheep::m_a = 18;
	st.Tuo::m_a = 28;
	//菱形继承时，两个父类拥有相同数据，需要加作用域区分
	cout << "st.Sheep::m_a = " << st.Sheep::m_a << endl;
	cout << "st.Tuo::m_a = " << st.Tuo::m_a << endl;
	//这份数据我们知道，只要有一份就可以了，菱形继承导致数据有两份，造成资源浪费

	//虚继承之后，不会出现二义性
	cout << "st.m_a = " << st.m_a << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//总结：

//*菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//* 利用虚继承可以解决菱形继承问题