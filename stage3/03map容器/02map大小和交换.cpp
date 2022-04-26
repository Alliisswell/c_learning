#include<iostream>
using namespace std;
#include<map>

/*
#### map大小和交换
**功能描述：**
* 统计map容器大小以及交换map容器

函数原型：
- `size();`          //返回容器中元素的数目
- `empty();`        //判断容器是否为空
- `swap(st);`      //交换两个集合容器
*/

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01() {
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	if (m.empty()) {
		cout << "m为空" << endl;
	}
	else {
		cout << "m不为空" << endl;
		cout << "m的大小为：" << m.size() << endl;
	}

}


void test02() {
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	map<int, int> m2;
	m2.insert(make_pair(4, 100));
	m2.insert(make_pair(5, 200));
	m2.insert(make_pair(6, 300));

	cout << "交换前：" << endl;
	printMap(m);
	printMap(m2);
	
	m2.swap(m);
	cout << "交换后：" << endl;
	printMap(m);
	printMap(m2);
}

int main() {

	test01();

	test02();

	system("pause");
	return 0;
}
/*
总结：
- 统计大小   --- size
- 判断是否为空   --- empty
- 交换容器   --- swap
*/