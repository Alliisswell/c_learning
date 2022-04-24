#include<iostream>
using namespace std;

/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性：

* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：

virtual ~类名(){};

纯虚析构语法：

virtual ~类名() = 0;

类名::~类名(){};
*/

class Animal {

public:
	Animal() {
		cout << "Animal构造函数调用" << endl;
	}

	//利用虚析构可以解决 父类指针释放子类对象不完全的问题
	//virtual ~Animal() {
	//	cout << "Animal析构函数调用" << endl;
	//}

	//纯虚析构
	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;
	
	//纯虚函数
	virtual void speak() = 0;
};

//纯虚析构函数需要在类内声明，也需要在类外实现
Animal::~Animal() {
	cout << "Animal纯虚析构函数调用" << endl;
}

class Cat :public Animal {

public:
	Cat(string name) {
		cout << "Cat构造函数调用" << endl;
		m_name = new string(name);
	}

	virtual void speak() {
		cout << *m_name << "小猫在说话" << endl;
	}

	~Cat() {
		if (m_name != NULL) {
			cout << "Cat析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	string* m_name;
};

void test01() {
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时候  不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
	delete animal;
}



int main() {

	test01();

	system("pause");
	return 0;
}