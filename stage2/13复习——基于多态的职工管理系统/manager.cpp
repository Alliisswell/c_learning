#include"manager.h"

Manager::Manager(int id, string name, int deptid) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}

void Manager::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并传达给员工" << endl;

}

string Manager::getDeptName() {
	return string("经理");
}