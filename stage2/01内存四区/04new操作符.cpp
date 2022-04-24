#include<iostream>

using namespace std;

//​	C++中利用 new 操作符在堆区开辟数据

//​	堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete 

//​	语法：new 数据类型

//​	利用new创建的数据，会返回该数据对应的类型的指针

//1、new的基本语法
int* func4() {
	//在堆区创建整形数据
	int* p = new int(10);  //new返回的是该数据类型的指针
	return p;
}


void test01() {
	int* p = func4();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据由程序员管理开辟，管理员管理释放
	//如果想释放堆区的数据，利用关键字 delete
	delete p;
	//cout << *p << endl;	//内存已经被释放，再次访问就是非法操作，会报错
}


//2、在堆区利用new开辟数组
void test02() {
	//在堆区创建10个整型数据的数组
	int* arr = new int[10];  //注意是中括号[]，10 代表数组有10个元素
	
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;	//给10个元素赋值，100 ~ 109
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	
	//释放堆区数组
	//释放数组的时候要加 [] 才行
	delete[] arr;

}

int main4() {

	test01();

	test02();

	system("pause");
	return 0;
}