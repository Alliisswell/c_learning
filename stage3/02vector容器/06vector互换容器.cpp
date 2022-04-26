#include<iostream>
using namespace std;
#include<vector>
/*
#### vector互换容器
**功能描述：**
* 实现两个容器内元素进行互换

**函数原型：**
* `swap(vec);`  // 将vec与本身的元素互换
*/
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//1、基本使用
void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	
	cout << "交换前v1：";
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i >0; i--) {
		v2.push_back(i);
	}

	cout << "交换前v2：";
	printVector(v2);

	v1.swap(v2);
	cout << "交换后v1：";
	printVector(v1);
	cout << "交换后v2：";
	printVector(v2);
}


//2、实际使用
//巧用swap可以收缩内存空间
void test02() {
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);  //重新指定大小
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//巧用swap收缩内存空间
	vector<int>(v).swap(v);  //vector<int>(v) --- 利用v创建的匿名对象，暂且记为x，x的大小为3（因为上边重新指定了大小）
							 //然后x和v进行互换，随后匿名对象x由系统回收
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

}

int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}

/*
总结：swap可以使两个容器互换，可以达到实用的收缩内存效果
*/