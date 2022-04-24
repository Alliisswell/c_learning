#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Person {

public:
	char m_name[64];	//姓名
	int m_age;	//年龄
};

void test01() {
	//1、包含头文件

	////2、创建流对象
	//ifstream ifs;

	////3、打开文件，并且判断文件是否打开成功
	//ifs.open("Person.txt",ios::in | ios::binary);  
	
	//2、3两步可以合为一步,利用的是ifs对象所属类的构造函数
	ifstream ifs("Person.txt", ios::in | ios::binary);
	
	if (!ifs.is_open()) {
		cout << "文件打开失败！！！" << endl;
		return;
	}
	//4、读文件
	Person p;
	ifs.read((char*)& p,sizeof(p));
	cout << "姓名：" << p.m_name << "\t年龄：" << p.m_age << endl;

	//5、关闭文件
	ifs.close();
}




int main() {

	test01();

	system("pause");
	return 0;
}