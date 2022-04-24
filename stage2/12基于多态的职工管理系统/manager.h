//经理文件
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager :public Worker {

public:

	//构造函数
	Manager(int id, string name, int did);

	//显示个人信息
	virtual void showInfo();

	//获取岗位
	virtual string getDeptName();
};

