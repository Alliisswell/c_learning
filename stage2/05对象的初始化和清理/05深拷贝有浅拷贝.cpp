#include<iostream>
using namespace std;

//深浅拷贝是面试经典问题，也是常见的一个坑

//浅拷贝：简单的赋值拷贝操作（当属性开辟在堆区时，浅拷贝会带来重复释放内存的问题，这时候就去要自己定义拷贝构造函数）

//深拷贝：在堆区重新申请空间，进行拷贝操作

//另外，当属性开辟在堆区，就要用到析构函数来进行释放操作


class Person {
public:
	Person() {
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age,int height) {
		cout << "Person的有参构造函数调用" << endl;
		m_age = age;	
		m_height = new int(height);	 //此属性就是开辟在堆区
	}

	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p) {
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;	//编译器默认实现就是这行代码
		//深拷贝操作
		m_height = new int(*p.m_height);  //解引用之后，重新在堆区再开辟内存来存放属性值，两个内存地址不一样，但是指向的属性值一样
	}

	~Person() {
		//析构代码，将堆区开辟数据做释放操作
		if (m_height!=NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_age = 0;	//年龄
	int* m_height = 0;	//身高
};

void test01() {	//栈上数据，先进后出，p2先被释放，然后释放p1的时候，如果只是浅拷贝就会引起交叉重复释放
	
	Person p1(18,160);
	cout << "p1的年龄为：" << p1.m_age << "\tp1的身高为：" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "\tp2的身高为：" << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题