#include<iostream>
#include<string>

/*
**案例描述：**

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。
*/

using namespace std;

//定义学生结构体
struct Student7
{
	string sName;
	int score;
};

//定义老师结构体
struct Teacher7
{
	string tName;
	Student7 sArray[5];
};

void allocateSpace(Teacher7 tArray[], int len) {
	string nameSeed = "ABCDE";
	//给老师赋值
	for (int i = 0; i < len; i++) {	
		
		tArray[i].tName = "Teacher7_";
		tArray[i].tName += nameSeed[i];

		// 给老师所带学生赋值
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student7_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand() % 61+40;	//40~100
			tArray[i].sArray[j].score = random;
		}
	}
}

void printInfo(Teacher7* tArray, int len) {
	for (int i = 0; i < len; i++) {
		cout << "老师姓名：" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t学生姓名：" << tArray[i].sArray[j].sName << " 考试分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main7() {
	srand((unsigned int)time(NULL));
	//1、创建3名老师数组
	Teacher7 tArray[3];

	//2、通过函数给3名老师的信息赋值，并给老师带的学生信息夫赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);

	//3、打印所有老师及所带学生的信息
	printInfo(tArray, len);

	system("pause");

	return 0;
}