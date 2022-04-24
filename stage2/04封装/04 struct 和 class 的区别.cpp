#include<iostream>

using namespace std;

//在C++中 struct 和 class 唯一的区别就在于 默认的访问权限不同
// struct 默认权限为 公共 public
// class 默认权限为 私有 private

struct C1 {
	int m_a = 0;	//默认权限是	公共 public
};

class C2 {
	int m_a = 0;	//默认权限是	私有 private
};


int main() {

	C1 c1;
	c1.m_a = 10;  //在 struct 中是公共成员，类外可以访问

	C2 c2;
	//c2.m_a = 10;	//在 class 中是私有成员，类外不可以访问


	system("pause");
	return 0;
}