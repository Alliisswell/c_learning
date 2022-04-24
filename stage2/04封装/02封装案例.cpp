#include<iostream>
#include<string>

using namespace std;

//设计一个学生类
//属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号

//学生类
class Student {
public:	//公共权限

	//类中的属性和行为 我们统一称为 成员
	//属性也称为 成员属性 或 成员变量
	//行为也成为 成员方法 或 成员函数

	//属性
	string m_name;	//姓名
	int m_id = 0;	//学号

	//行为
	//显示姓名和学号
	void showStudent() {
		cout << "姓名：" << m_name << "\t学号：" << m_id << endl;
	}

	//给姓名赋值
	void setName(string name) {
		m_name = name;
	}

	//给学号赋值
	void setId(int id) {
		m_id = id;
	}

};
int main() {

	//实例化 通过学生类创建一个学生对象
	Student s1;
	//给s1对象 进行属性赋值操作
	/*s1.m_name = "张三";
	s1.m_id = 209802020;
	s1.showStudent();*/

	s1.setName("张三");
	s1.setId(219802020);
	s1.showStudent();

	system("pause");
	return 0;
}