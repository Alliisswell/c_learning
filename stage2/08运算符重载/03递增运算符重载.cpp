#include<iostream>
using namespace std;

//作用：通过重载递增运算符，实现自己的整型数据

//自定义的整型
class MyInteger {
	
	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_num = 0;
	}

	//重载 前置++ 运算符  返回引用是为了一直对一个数据进行递增操作（链式编程）
	MyInteger& operator++() {
		//先进行++运算
		m_num++;
		//再将自身做返回
		return *this;
	}
	//重载 后置++ 运算符  记住要返回值，而不返回引用
	//void operator++(int)  这个 int 代表占位参数，可以用于区分 前置递增 和 后置递增
	MyInteger operator++(int) {  //这里返回不是引用，是因为temp是局部变量，代码运行完就被释放，如果还以引用的方式返回就属于非法操作
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_num++;
		//最后 将记录结果做返回
		return temp;
	}


private:
	int m_num;
};

//重载左移运算符
ostream& operator<<(ostream& out,MyInteger myint) {
	out << myint.m_num;
	return out;
}

//前置++ 先++ 再返回
void test01() {
	MyInteger myint;
	//cout << ++(++myint) << endl;
	//cout << myint << endl;
	cout << ++(++myint) << " "<< myint << endl;

}
	

//后置++ 先返回 再++
void test02() {
	MyInteger myint;
	//cout << myint++ << endl;
	//cout << myint << endl;
	cout << myint++ <<" "<< myint << endl;	//如果重载左移运算符全局函数中的第二个参数使用引用就会报错
}

int main() {

	test01();
	test02();


	system("pause");
	return 0;
}

//总结：前置递增返回引用，后置递增返回值