#include<iostream>
#include<string>

using namespace std;

//结构体数组
//**作用：** 将自定义的结构体放入到数组中方便维护
//**语法：** struct  结构体名 数组名[元素个数] = { {} , {} , ... {} }

//1、定义结构体
struct Student2 
{
	//成员列表
	string name;	//姓名
	int age;	//年龄
	int score;	//分数
};

int main2() {
	//2、创建结构体数组 
	struct Student2 stuArray[3] = {
		{"张三",18,100},
		{"李四",28,88},
		{"王五",38,66}
	};
	
	//3、给结构体数组中的元素赋值
	//stuArray[2] = {"赵六",48,60};
	stuArray[2].name = "赵六";
	stuArray[2].age = 48;
	stuArray[2].score = 60;
	
	//4、遍历结构体数组
	for (int i = 0; i < 3; i++) {
		cout << "姓名：" << stuArray[i].name << " 年龄：" << stuArray[i].age << " 成绩：" << stuArray[i].score << endl;
	}
	system("pause");

	return 0;
}