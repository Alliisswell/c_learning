#include<iostream>
using namespace std;
#include<list>

/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/

//void printList(list<Person>& L) {
	
//}

class Person {
public:
	Person(string name,int age,int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}


	string m_name;  //姓名
	int m_age;  //年龄
	int m_height;  //身高

};

//指定排序规则
bool comparePerson(Person& p1,Person& p2) {
	//按照年龄  升序
	if (p1.m_age == p2.m_age) {
		//年龄相同  按照身高排序  降序
		return p1.m_height > p2.m_height;
	}
	return p1.m_age < p2.m_age;
}

void test01() {
	
	list<Person> L;  //创建容器
	
	//准备数据
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	
	//插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名：" << (*it).m_name << " 年龄：" << (*it).m_age << " 身高：" << (*it).m_height << endl;
	}
	//printList(L);

	//排序
	cout << "---------------------------------" << endl;
	cout << "排序后：" << endl;

	L.sort(comparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名：" << (*it).m_name << " 年龄：" << (*it).m_age << " 身高：" << (*it).m_height << endl;
	}
}

int main() {

	test01();

	system("pause");
	return 0;
}

/*
总结：
* 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
* 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
*/