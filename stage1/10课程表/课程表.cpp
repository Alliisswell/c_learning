#include<iostream>
#include<string>
#include <windows.h>
#include <stdio.h> 

using namespace std;

//定义课程信息结构体
struct Courseinfo
{
	string course_name; 
	string course_addr;
};

//定义课程表结构体
struct Course
{
	Courseinfo course_table[6][8];
};

//1、添加课程
void addCourse(Course* course) { 
	while (true) {
		cout << "请输入星期：" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "请输入单元：" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			cout << "请输入名称：" << endl;
			string name;
			cin >> name;
			course->course_table[uint_id][week_id].course_name = name;

			cout << "请输入地址：" << endl;
			string addr;
			cin >> addr;
			course->course_table[uint_id][week_id].course_addr = addr;
			cout << "已成功添加课程！" << endl;
			break;
		}
		cout << "输入错误，请重新输入！" << endl;
	}
	
	system("pause");
	system("cls");
}

//2、删除课程
void deletCourse(Course* course) {
	while (true) {
		cout << "请输入星期：" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "请输入单元：" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			course->course_table[uint_id][week_id].course_name = "####";
			course->course_table[uint_id][week_id].course_addr = "###";
			cout << "已成功删除课程！" << endl;

			break;
		}
		cout << "输入错误，请重新输入！" << endl;
	}

	system("pause");
	system("cls");
}
	

//3、修改课程
void modifyCourse(Course* course) {
	while (true) {
		cout << "请输入星期：" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "请输入单元：" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			cout << "请输入名称：" << endl;
			string name;
			cin >> name;
			course->course_table[uint_id][week_id].course_name = name;

			cout << "请输入地址：" << endl;
			string addr;
			cin >> addr;
			course->course_table[uint_id][week_id].course_addr = addr;
			cout << "已成功修改课程！" << endl;
			break;
		}
		cout << "输入错误，请重新输入！" << endl;
	}

	system("pause");
	system("cls");
}

////4、刷新课程
//void refreshCourse(Course* course) {
//	
//}

//初始化课程表
void cinCourse(Course* course) {
	//初始化表格第一行和第一列
	course->course_table[0][0].course_name = "单元/星期 ";
	course->course_table[0][0].course_addr = "";
	course->course_table[0][1].course_name = "星期一\t";
	course->course_table[0][1].course_addr = "";
	course->course_table[0][2].course_name = "星期二\t";
	course->course_table[0][2].course_addr = "";
	course->course_table[0][3].course_name = "星期三\t";
	course->course_table[0][3].course_addr = "";
	course->course_table[0][4].course_name = "星期四\t";
	course->course_table[0][4].course_addr = "";
	course->course_table[0][5].course_name = "星期五\t";
	course->course_table[0][5].course_addr = "";
	course->course_table[0][6].course_name = "星期六\t";
	course->course_table[0][6].course_addr = "";
	course->course_table[0][7].course_name = "星期日";
	course->course_table[0][7].course_addr = "";
	course->course_table[1][0].course_name = "   一单元";
	course->course_table[1][0].course_addr = "";
	course->course_table[2][0].course_name = "   二单元";
	course->course_table[2][0].course_addr = "";
	course->course_table[3][0].course_name = "   三单元";
	course->course_table[3][0].course_addr = "";
	course->course_table[4][0].course_name = "   四单元";
	course->course_table[4][0].course_addr = "";
	course->course_table[5][0].course_name = "   五单元";
	course->course_table[5][0].course_addr = "";
	//初始化课程信息
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 8; j++) {
			course->course_table[i][j].course_name = "####";
			course->course_table[i][j].course_addr = "###";
		}
	}
}


//菜单界面
void showMenu(Course* course) {
	
	//时间
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << "今天是\t" << sys.wYear << "年" << sys.wMonth << "月" << sys.wDay << "日" << "\t" << "星期 " << sys.wDayOfWeek
		<< "\t    " << sys.wHour << " 时 " << sys.wMinute << " 分 " << sys.wSecond << " 秒 " << endl;
	//表头
	cout << "《辽宁工业大学2020/2021学年第一学期课程表》" << endl;
	cout << "**********************************************************************************************************************************" << endl;
	
	//打印课程表
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			cout << course->course_table[i][j].course_name
				<< " " << course->course_table[i][j].course_addr << "\t";
		}
		cout << "\n";
		cout << endl;
	}

	cout << "**********************************************************************************************************************************" << endl;
	cout << "*****\t注意：请简写课程名称为两个字，教室信息为三个数字\t*****" << endl;
	cout << "*****\t1、添加课程\t*****" << endl;
	cout << "*****\t2、删除课程\t*****" << endl;
	cout << "*****\t3、修改课程\t*****" << endl;
	cout << "*****\t0、退出课程表\t*****" << endl;
}
	
		
	



int main() {

	Course course;
	
	cinCourse(&course);
	
	int select = 0;
	while (true) {
		
		showMenu(&course);

		cin >> select;
		switch (select) {
		case 1:	//添加课程
			addCourse(&course);
			break;
		case 2:	//删除课程
			deletCourse(&course);
			break;
		case 3:	//修改课程
			modifyCourse(&course);
			break;
		case 0:	//退出课程表
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
	//Sleep(10);
}