#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker {

public:

	//显示个人信息
	virtual void showInfo() = 0;	//多态  一个接口，多种形态

	//获取岗位
	virtual string getDeptName() = 0;	//多态  一个接口，多种形态

	int m_id;  //职工编号
	string m_name;  //职工姓名
	int m_deptid;  //部门编号


};