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
		cout << "������" << m_name << "\tѧ�ţ�" << m_id << endl;
	}

};


int main() {

	Student s1;

	s1.setInfo("����", 1234);

	s1.showInfo();

	system("pause");
	return 0;
}