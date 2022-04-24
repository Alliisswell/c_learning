#include<iostream>
using namespace std;
#include<fstream>
#include<string>

class Person {

public:
	char m_name[64];	//姓名
	int m_age;	//年龄
};


void test01() {
	//1、包含头文件

	////2、创建流对象
	//ofstream ofs;

	////3、打开文件
	//ofs.open("Person.txt", ios::out | ios::binary);

	//2、3两步可以合为一步，利用ofs对象所属类的构造函数
	ofstream ofs("Person.txt",ios::out | ios::binary);

	//4、写文件
	Person p = {"张三",18};
	ofs.write((const char*)& p, sizeof(Person));

	//5、关闭文件
	ofs.close();

}




int main() {

	test01();

	system("pause");
	return 0;
}