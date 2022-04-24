#pragma once	//防止头文件重复包含
#include<iostream>	//包含输入输出流文件
using namespace std;	//使用标准命名空间
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager {

public:
	
	//构造函数
	WorkerManager();	
	
	//展示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//记录职工人数
	int m_empnum;

	//职工数组指针
	Worker** m_emparray;

	//添加职工
	void addEmp();

	//保存文件
	void saveFile();

	//判断文件是否为空的标志
	bool m_fileisempty;

	//统计文件中人数
	int getEmpNum();

	//初始化职工
	void initEmpArray();

	//显示职工
	void showEmp();

	//按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
	int isExit(int id);

	//删除职工
	void deleteEmp();

	//修改职工
	void modifyEmp();

	//查找职工
	void searchEmp();

	//排序职工
	void sortEmp();

	//清空文件
	void cleanEmp();
	
	//析构函数
	~WorkerManager();	

};