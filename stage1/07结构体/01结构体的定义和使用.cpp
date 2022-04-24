#include<iostream>
#include<string>

using namespace std;

//结构体：用户自定义的数据类型，允许用户存储不同的数据类型，可以理解为一些系统提供的数据类型组成的一个数据类型
//语法：struct 结构体名 { 结构体成员列表 }；

//通过结构体创建变量的方式有三种：
//* struct 结构体名 变量名
//* struct 结构体名 变量名 = { 成员1值 ， 成员2值... }
//* 定义结构体时顺便创建变量

//结构体定义
struct Student1
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};


int main1() {

	//结构体变量创建方式1
	struct Student1 stu1; //struct 关键字可以省略

	stu1.name = "张三";
	stu1.age = 18;
	stu1.score = 100;

	cout << "姓名：" << stu1.name << " 年龄：" << stu1.age << " 分数：" << stu1.score << endl;

	//结构体变量创建方式2
	struct Student1 stu2 = { "李四",19,60 };

	cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" << stu2.score << endl;

//总结1：定义结构体时的关键字是struct，不可省略

//总结2：创建结构体变量时，关键字struct可以省略

//总结3：结构体变量利用操作符“.”访问成员

	system("pause");

	return 0;
}

/*

#include<iostream>
#include<string>

using namespace std;

int main(){
	


	system("pause");

	return 0;
}

*/