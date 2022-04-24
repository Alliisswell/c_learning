#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int deptid);

	virtual void showInfo();

	virtual string getDeptName();

};
