#include<iostream>
using namespace std;
#include<fstream>
#include<string>

class Person {

public:
	char m_name[64];	//����
	int m_age;	//����
};


void test01() {
	//1������ͷ�ļ�

	////2������������
	//ofstream ofs;

	////3�����ļ�
	//ofs.open("Person.txt", ios::out | ios::binary);

	//2��3�������Ժ�Ϊһ��������ofs����������Ĺ��캯��
	ofstream ofs("Person.txt",ios::out | ios::binary);

	//4��д�ļ�
	Person p = {"����",18};
	ofs.write((const char*)& p, sizeof(Person));

	//5���ر��ļ�
	ofs.close();

}




int main() {

	test01();

	system("pause");
	return 0;
}