#include<iostream>
using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal {
public:
	virtual void speak() {	//��������д����ĺ���ʱ�������е��麯�����ڲ����滻��������麯����ַ
		cout << "Сè��˵��" << endl;
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
	cout << "size of Animal = " << sizeof(Animal) << endl;	//32λϵͳָ��ռ4���ֽ��ڴ�ռ䣬64λϵͳռ8���ֽ�
}

int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}