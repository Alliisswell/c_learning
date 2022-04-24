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

class Son :public Base {
public:
	int m_d;
};

//利用开发人员命令提示符工具查看对象模型
//跳转盘符  盘符:
//跳转路径  cd 具体路径
//查看目录  dir
//查看命令  cl /d1 reportSingleClassLayout类名 文件名  （cl英文，d1数字一，文件名用Tab键补全）

void test01() {
	cout << "size of Son = " << sizeof(Son) << endl;
	//16
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性，是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
	cout << "size of Base = " << sizeof(Base) << endl;
	//12
}





int main() {

	test01();

	system("pause");
	return 0;
}