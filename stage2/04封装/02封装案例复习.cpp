#include<iostream>
using namespace std;


class Student {
public:
	string m_name;
	int m_id;


	void setInfo(string name, int id) {
		m_name = name;
		m_id = id;
	}

	void showInfo() {
		cout << "姓名：" << m_name << "\t学号：" << m_id << endl;
	}

};


int main() {

	Student s1;

	s1.setInfo("张三", 1234);

	s1.showInfo();

	system("pause");
	return 0;
}