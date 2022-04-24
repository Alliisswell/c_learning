#include<iostream>
using namespace std;

class Base {

public:
	int m_a = 0;
protected:
	int m_b = 0;
private:
	int m_c = 0;
};

//公共继承
class Son1 :public Base {

public:
	void func() {
		m_a = 10;	//父类中的公共权限成员，到子类中依然是公共权限
		m_b = 10;	//父类中的保护权限成员，到子类中依然是保护权限
		//m_c = 10;	//父类中的私有权限成员，子类访问不到
	}
};

void test01() {
	Son1 s1;
	s1.m_a = 100;
	//s1.m_b = 100;	//到Son1中，m_b 是保护权限，类外访问不到
}

//保护继承
class Son2 :protected Base {
public:
	void func() {
		m_a = 10;	//父类中的公共权限成员，到子类中变为保护权限
		m_b = 10;	//父类中的公共权限成员，到子类中变为保护权限
		//m_c = 10;	//父类中的私有权限成员，子类访问不到
	}
};

void test02() {
	Son2 s2;
	//s2.m_a = 100;	//到Son2中，m_a 变为保护权限，类外访问不到
	//s2.m_b = 100;	//到Son2中，m_b 变为保护权限，类外访问不到
}

//私有继承
class Son3 :private Base {
public:
	void func() {
		m_a = 10;	//父类中的公共权限成员，到子类中变为私有权限
		m_b = 10;	//父类中的公共权限成员，到子类中变为私有权限
		//m_c = 10;	//父类中的私有权限成员，子类访问不到
	}
};

void test03() {
	Son3 s3;
	//s3.m_a = 100;	//到Son3中，m_a 变为私有权限，类外访问不到
	//s3.m_b = 100;	//到Son3中，m_b 变为私有权限，类外访问不到
}

//再次验证“到Son3中，m_a 和 m_b 变为私有权限，类外访问不到”
class GrandSon3 :public Son3 {	//由于父类 Son3 中 m_a 和 m_b 是私有成员，即使是公共继承方式，也访问不到
public:
	void func() {
		//m_a = 1000;	//父类 Son3 中的私有权限成员，子类 GrandSon3 访问不到
		//m_b = 1000;	//父类 Son3 中的私有权限成员，子类 GrandSon3 访问不到
	}

};

int main() {



	system("pause");
	return 0;
}