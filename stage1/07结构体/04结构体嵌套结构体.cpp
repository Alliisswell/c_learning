#include<iostream>
#include<string>

using namespace std;

//**作用：** 结构体中的成员可以是另一个结构体
//
//**例如：** 每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

struct Student4
{
	string name;
	int age;
	int score;
};

struct Teacher4
{
	string name;
	int id;
	int age;
	
	Student4 stu;	//子结构体，学生stu
};

int main4() {

	Teacher4 tea;
	tea.name = "老王";
	tea.id = 1000;
	tea.age = 40;
	tea.stu.name = "张三";
	tea.stu.age = 18;
	tea.stu.score = 100;

	cout << "老师姓名：" << tea.name << " 老师编号：" << tea.id << " 老师年龄：" << tea.age << endl;
	cout << "老师辅导的学生姓名：" << tea.stu.name << " 老师辅导的学生年龄：" << tea.stu.age
		<< " 老师辅导的学生分数：" << tea.stu.score << endl;

	system("pause");

	return 0;
}

//**总结：** 在结构体中可以定义另一个结构体作为成员，用来解决实际问题