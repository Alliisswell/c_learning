#include<iostream>
using namespace std;

//案例描述：
//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

//利用普通写法实现计算器
class Caculator {

public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		} 
		else if(oper == "*") {
			return m_num1 * m_num2;
		}
	}
	
	//如果想扩展新的功能，需要修改源码
	//在真实开发中，提倡 开闭原则
	//开闭原则：对扩展进行开发，对修改进行关闭

	int m_num1;	//操作数1
	int m_num2;	//操作数2
};

//利用多态实现计算器
//多态的优点：
//* 代码组织结构清晰
//* 可读性强
//* 利于前期和后期的扩展以及维护

//实现计算机抽象类
class AbstractCaculator {

public:
	virtual int getResult() {
		return 0;
	}

	int m_num1;
	int m_num2;
};

//加法计算器类
class addCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 + m_num2;
	}

};

//减法计算器类
class subCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 - m_num2;
	}

};

//乘法计算器类
class mulCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 * m_num2;
	}

};

void test01() {
	Caculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;
	
	cout << c.m_num1 << " + " << c.m_num2 << " = " << c.getResult("+") << endl;
	cout << c.m_num1 << " - " << c.m_num2 << " = " << c.getResult("-") << endl;
	cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getResult("*") << endl;
}

void test02() {
	//动态多态使用
	//父类的指针或引用 指向子类对象

	//加法运算
	AbstractCaculator* abc = new addCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;

	//减法运算
	abc = new subCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;

	//乘法运算
	abc = new mulCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
}




int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}