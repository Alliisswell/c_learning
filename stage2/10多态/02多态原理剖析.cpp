#include<iostream>
using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	virtual void speak() {	//当子类重写父类的函数时，子类中的虚函数表内部会替换成子类的虚函数地址
		cout << "小猫在说话" << endl;
	}
};

void doSpeak(Animal& animal) {	
	animal.speak();
}

void test01() {
	Cat cat;
	doSpeak(cat);
}

void test02() {
	cout << "size of Animal = " << sizeof(Animal) << endl;	//32位系统指针占4个字节内存空间，64位系统占8个字节
}

int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}