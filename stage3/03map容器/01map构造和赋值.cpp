/*
#### map��������
**��飺**
* map������Ԫ�ض���pair
* pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
* ����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

**���ʣ�**
* map/multimap����**����ʽ����**���ײ�ṹ���ö�����ʵ�֡�

**�ŵ㣺**
* ���Ը���keyֵ�����ҵ�valueֵ

map��multimap**����**��
- map���������������ظ�keyֵԪ��
- multimap�������������ظ�keyֵԪ��
*/

/*
#### map����͸�ֵ
**����������**
* ��map�������й���͸�ֵ����

**����ԭ�ͣ�**
**���죺**
* `map<T1, T2> mp;`                     //mapĬ�Ϲ��캯��:
* `map(const map &mp);`             //�������캯��

**��ֵ��**
* `map& operator=(const map &mp);`    //���صȺŲ�����
*/

#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << (*it).first <<" value = "<< it->second << endl;
	}
	cout << endl;
}

void test01() {
	map<int, int> m;
	
	//���ö����������
	m.insert(make_pair(1, 10));  //pair<int,int>(1,10)�������������������������map������ֵ
	m.insert(make_pair(3, 30));  //����keyֵ�������Ժ���������keyֵ���
	m.insert(make_pair(2, 20));
	m.insert(make_pair(4, 40));

	printMap(m);

	//��������
	map<int, int>m2(m);
	printMap(m2);

	//��ֵ
	map<int, int>m3;
	m3 = m2;
	printMap(m3);

}

int main() {

	test01();

	system("pause");
	return 0;
}

/*
�ܽ᣺map������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���
*/

/*
#include<iostream>
using namespace std;
#include<map>

int main() {

	system("pause");
	return 0;
}
*/