#include<iostream>
using namespace std;
#include<map>
/*
#### map���Һ�ͳ��
**����������**

- ��map�������в��������Լ�ͳ������

**����ԭ�ͣ�**
- `find(key);`                  //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����.end();
- `count(key);`                //ͳ��key��Ԫ�ظ���  ����map���������Ϊ0��1������multimap����count(key)������ֵ
*/
void test01() {

	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//����
	////����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����.end();
	map<int,int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "�鵽��Ԫ�� key = " << (*pos).first << " value = " << pos->second << endl;
	}
	else {
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	//map����������ظ�keyԪ�أ�countͳ�ƽ��Ҫô��0Ҫô��1��multimap��count������ܴ���1
	int num = m.count(3);
	cout << "num = " << num << endl;

}

int main() {

	test01();

	system("pause");
	return 0;
}
/*
�ܽ᣺
- ����   ---  find    �����ص��ǵ�������
- ͳ��   ---  count  ������map�����Ϊ0����1��
*/