#include<iostream>
using namespace std;
#include"workManager.h"


int main() {

	WorkerManager wm;

	int select = 0;

	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 0://0.退出管理程序
			wm.exitMenu();
			break;
		case 1://1.增加职工信息
			wm.addEmp();
			break;
		case 2://2.显示职工信息
			wm.showEmp();
			break;
		case 3://3.删除职工信息（按照职工编号）
			wm.deleteEmp();
			break;
		case 4://4.修改职工信息（按照职工编号）
			wm.modifyEmp();
			break;
		case 5://5.查找职工信息
			wm.searchEmp();
			break;
		case 6://6.按照编号排序
			wm.sortEmp();
			break;
		case 7://7.清空所有文档
			wm.cleanFile();
			break;
		default:
			cout << "输入有误，请重新输入：" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}


