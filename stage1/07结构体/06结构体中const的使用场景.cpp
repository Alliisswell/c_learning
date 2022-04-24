#include<iostream>
#include<string>

using namespace std;

//**作用：** 用const来防止误操作

struct Student6
{
	string name;
	int age;
	int score;
};

void printStudent6(const Student6* s) {	////加const防止函数体中的误操作
	//s->age = 80;	////操作失败，因为加了const修饰
	cout << "子函数中姓名：" << s->name << " 年龄：" << s->age
		<< " 分数：" << s->score << endl;
}

int main6() {

	Student6 stu = { "张三",18,100 };

	printStudent6(&stu);

	system("pause");

	return 0;
}