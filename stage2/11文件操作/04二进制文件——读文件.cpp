#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Person {

public:
	char m_name[64];	//����
	int m_age;	//����
};

void test01() {
	//1������ͷ�ļ�

	////2������������
	//ifstream ifs;

	////3�����ļ��������ж��ļ��Ƿ�򿪳ɹ�
	//ifs.open("Person.txt",ios::in | ios::binary);  
	
	//2��3�������Ժ�Ϊһ��,���õ���ifs����������Ĺ��캯��
	ifstream ifs("Person.txt", ios::in | ios::binary);
	
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�����" << endl;
		return;
	}
	//4�����ļ�
	Person p;
	ifs.read((char*)& p,sizeof(p));
	cout << "������" << p.m_name << "\t���䣺" << p.m_age << endl;

	//5���ر��ļ�
	ifs.close();
}




int main() {

	test01();

	system("pause");
	return 0;
}