#include<iostream>

using namespace std;

//三种访问权限
//公共权限 public		成员 类内可以访问 类外可以访问
//保护权限 protected	成员 类内可以访问 类外不可以访问 儿子可以访问父亲中的保护内容
//私有权限 private		成员 类内可以访问 类外不可以访问 儿子不可以访问父亲的私有内容

class Person {
public:
	//公共权限
	string m_name;

protected:
	//保护权限
	string m_car;

private:
	//私有权限
	int m_password;

public:	//此处的权限类别，规定的是接下来写的 行为 的被访问权限
	void func() {	//类内可以访问
		m_name = "张三";
		m_car = "拖拉机";
		m_password = 123456;
	}
};


int main() {

	//实例化具体对象
	Person p1;

	p1.m_name = "李四";
	//p1.m_car = "奔驰";	//保护权限内容，在类外访问不到
	//p1.m_password = 123;  //私有权限内容，在类外访问不到

	p1.func();  //此成员函数权限为公共权限，可以访问，不会报错




	system("pause");
	return 0;
}