#include<iostream>
#include<string>

using namespace std;

//成员属性设置为私有的好处
//**优点1：** 将所有成员属性设置为私有，然后通过设置接口（共有权限的成员行为）进而可以自己控制成员属性的读写权限
//**优点2：** 对于写权限，我们可以检测数据的有效性

//设计人类
class Person {
public:
	//设置姓名
	void setName(string name) {
		m_name = name;
	}
	//获取姓名
	string getName() {
		return m_name;
	}

	//设置年龄
	void setAge(int age) {  //对于写权限，我们可以检测用户输入数据的有效性
		if (age < 0 || age > 150) {
			m_age = 0;
			cout << "你个老妖精!" << endl;
			return;
		}
		m_age = age;
	}
	//获取年龄
	int getAge() {
		m_age = 0;
		return m_age;
	}

	//设置情人
	void setLover(string lover) {
		m_lover = lover;
	}

private:
	string m_name = "张三";	//姓名	可读可写
	int m_age;	//年龄	可读可写
	string m_lover;	//情人	只写
};


int main() {

	Person p;
	//姓名	可读可写
	p.setName("张三");
	cout << "姓名：" << p.getName() << endl;

	//年龄	可读可写
	p.setAge(1000);
	cout << "年龄：" << p.getAge() << endl;

	//情人	只写
	p.setLover("仓井");

	system("pause");
	return 0;
}