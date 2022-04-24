#pragma once
#include<iostream>
using namespace std;

class Worker {
public:

	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

	int m_id;
	string m_name;
	int m_deptid;
};