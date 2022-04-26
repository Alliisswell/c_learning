#include<iostream>
using namespace std;
#include<map>
/*
#### map查找和统计
**功能描述：**

- 对map容器进行查找数据以及统计数据

**函数原型：**
- `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回.end();
- `count(key);`                //统计key的元素个数  对于map容器，结果为0或1，对于multimap而言count(key)有其他值
*/
void test01() {

	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//查找
	////查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回.end();
	map<int,int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "查到了元素 key = " << (*pos).first << " value = " << pos->second << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}

	//统计
	//map不允许插入重复key元素，count统计结果要么是0要么是1，multimap的count结果可能大于1
	int num = m.count(3);
	cout << "num = " << num << endl;

}

int main() {

	test01();

	system("pause");
	return 0;
}
/*
总结：
- 查找   ---  find    （返回的是迭代器）
- 统计   ---  count  （对于map，结果为0或者1）
*/