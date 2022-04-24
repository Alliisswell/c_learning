#include<iostream>
#include<string>

using namespace std;

//**作用：** 将结构体作为参数向函数中传递

//传递方式有两种：
//* 值传递
//* 地址传递

struct Student5
{
	string name;
	int age;
	int score;
};

void printStudent1(Student5 s) {
	s.age = 80;
	cout << "子函数中姓名：" << s.name << " 年龄：" << s.age
		<< " 分数：" << s.score << endl;
}

void printStudent2(Student5* s) {
	s->age = 80;
	cout << "子函数中姓名：" << s->name << " 年龄：" << s->age
		<< " 分数：" << s->score << endl;
}

int main5() {
	//创建结构体变量
	Student5 stu= {"张三",18,100};

	//将学生传入到一个函数中，打印学生身上的所有信息
	
	//值传递
	//printStudent1(stu);
	
	//地址传递
	printStudent2(&stu);

	cout << "姓名：" << stu.name << " 年龄：" << stu.age
		<< " 分数：" << stu.score << endl;	//对比输出



	system("pause");

	return 0;
}

//总结：如果不想修改主函数中的数据，用值传递，反之用地址传递