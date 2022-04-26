#include<iostream>
using namespace std;
#include<vector>
/*
####  vector容量和大小
**功能描述：**
* 对vector容器的容量和大小操作

**函数原型：**
* `empty(); `                            //判断容器是否为空
* `capacity();`                      //容器的容量
* `size();`                              //返回容器中元素的个数
* `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					      //如果容器变短，则末尾超出容器长度的元素被删除。
* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				              //如果容器变短，则末尾超出容器长度的元素被删除
*/
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector<int> v;
	
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	printVector(v);

	if (v.empty()) {
		cout << "v为空" << endl;
	}
	else {
		cout << "v不为空" << endl;
	}

	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;

	v.resize(15);
	printVector(v);  //如果重新指定的大小比原来的大，默认用0填充新的位置

	//v.resize(15,100);
	//printVector(v);  //当然，可以指定默认填充值，参数2

	v.resize(8);
	printVector(v);  //如果重新指定的大小比原来小，超出部分会删除掉
	

}

int main() {

	test01();

	system("pause");
	return 0;
}

/*
总结：
* 判断是否为空  --- empty
* 返回元素个数  --- size
* 返回容器容量  --- capacity
* 重新指定大小  ---  resize
*/