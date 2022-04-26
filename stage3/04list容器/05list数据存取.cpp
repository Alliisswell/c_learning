#include<iostream>
using namespace std;
#include<list>
/*
#### list 数据存取
**功能描述：**
* 对list容器中数据进行存取

**函数原型：**
* `front();`        //返回第一个元素。
* `back();`         //返回最后一个元素。
*/
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	list<int> L1; 

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	//L1[0]  不可以用[]访问list容器中的元素，原因是list底层没有重载[]符号
	
	//L1.at(0)  不可以用at方式访问list容器中的元素，原因：list本质是一个链表，不是用连续的空间来存储数据的，迭代器也是不支持随机访问的

	
	cout << "第一个元素是：" << L1.front() << endl;
	cout << "最后一个元素是：" << L1.back() << endl;

	//验证迭代器是不支持随机访问的  此处技巧可以用来验证其他迭代器是否可以双向随机访问，就不用死记硬背了
	list<int>::iterator it = L1.begin();
	it++;  //双向迭代器，若只能++则是前向迭代器
	it--;
	//it = it + 1;  不支持随机访问
	//it = it - 1;

}

int main() {

	test01();

	system("pause");
	return 0;
}
/*
总结：
* list容器中不可以通过[]或者at方式访问数据
* 返回第一个元素   --- front
* 返回最后一个元素   --- back
*/
