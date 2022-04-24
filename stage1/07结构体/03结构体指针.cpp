#include<iostream>
#include<string>

using namespace std;

//**作用：** 通过指针访问结构体中的成员
//利用操作符 “->” 可以通过结构体指针访问结构体属性

//定义学生结构体
struct Student3
{
	string name;
	int age;
	int score;
};

int main3() {

	//创建学生结构体变量
	Student3 stu = {"张三",18,100};
	
	//通过指针指向结构体变量
	Student3* p = &stu;	//指针的数据类型为 Student3
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

	system("pause");
	return 0;
}