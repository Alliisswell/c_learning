/*
### STL的诞生
* 长久以来，软件界一直希望建立一种可重复利用的东西
* C++的**面向对象**和**泛型编程**思想，目的就是**复用性的提升**
* 大多情况下，数据结构和算法都未能有一套标准,导致被迫从事大量重复工作
* 为了建立数据结构和算法的一套标准,诞生了**STL**

### STL基本概念
* STL(Standard Template Library,**标准模板库**)
* STL 从广义上分为: **容器(container) 算法(algorithm) 迭代器(iterator)**
* **容器**和**算法**之间通过**迭代器**进行无缝连接。
* STL 几乎所有的代码都采用了模板类或者模板函数

### STL六大组件
STL大体分为六大组件，分别是:**容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器**
1. 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据。
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂。
4. 仿函数：行为类似函数，可作为算法的某种策略。
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
6. 空间配置器：负责空间的配置与管理。

### STL中容器、算法、迭代器

**容器：**置物之所也
STL**容器**就是将运用**最广泛的一些数据结构**实现出来
常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表 等
这些容器分为**序列式容器**和**关联式容器**两种:
​	**序列式容器**:强调值的排序，序列式容器中的每个元素均有固定的位置。
​	**关联式容器**:二叉树结构，各元素之间没有严格的物理上的顺序关系

**算法：**问题之解法也
有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
算法分为:**质变算法**和**非质变算法**。
质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

**迭代器：**容器和算法之间粘合剂
提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
每个容器都有自己专属的迭代器
迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
*/

/*
#### vector存放内置数据类型

容器：vector（矢量，向量）

算法：for_each

迭代器：vector<int>::iterator
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void myPrint(int val) {
	cout << val << endl;
}

void test01() {
	//创建了一个vector容器（数组）
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器（指针）访问容器中的数据
	//vector<int>::iterator itbegin = v.begin();  //起始迭代器  指向容器中第一个元素
	//vector<int>::iterator itend = v.end();  //结束迭代器  指向容器中最后一个元素的下一个位置

	//第一种访问方式
	//while (itbegin != itend) {
	//	cout << *itbegin << endl;
	//	itbegin++;
	//}

	//第二种访问方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	//第三种访问方式  利用STL提供的便利算法
	for_each(v.begin(),v.end(),myPrint);



}





int main() {

	test01();


	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;







int main() {




	system("pause");
	return 0;
}
*/