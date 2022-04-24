/*
### 1.2 程序运行后（栈区，堆区）
	
	**堆区：**

​		由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
​		
		在C++中主要利用new在堆区开辟内存
*/
#include<iostream>

using namespace std;

int* func3() {
	
	//利用关键字new，可以将数据开辟到堆区
	//指针  本质也是局部变量，放在栈上，而指针指向的数据放在堆区
	int* p = new int(10);  //new返回的是该数据类型的指针
	return p;
}

int main3() {

	//在堆区开辟数据
	int* p = func3();
	cout << *p << endl;
	cout << *p << endl;  //运行过程中程序员不操作就不会被释放，只有程序结束时，由操作系统回收

	system("pause");
	return 0;
}

/*
**总结：**

堆区数据由程序员管理开辟和释放

堆区数据利用new关键字进行开辟内存
*/