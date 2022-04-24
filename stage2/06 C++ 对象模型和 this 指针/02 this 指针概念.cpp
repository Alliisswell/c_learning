#include<iostream>
using namespace std;

/*
ͨ���Ͻڿ�����֪����C++�г�Ա�����ͳ�Ա�����Ƿֿ��洢��
ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����

��ô�����ǣ���һ���������������Ǹ���������Լ����أ�
c++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⡣**thisָ��ָ�򱻵��õĳ�Ա���������Ķ���**

thisָ����������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

thisָ�����;��
1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
2������ķǾ�̬��Ա�����з��ض�������ʹ��return *this
*/

class Person {
public:
	Person(int age) {
		//thisָ��ָ����� �����õĳ�Ա���� �����Ķ���
		this->age = age;
	
	}

	Person& personAddAge(Person& p) {	//ע���� ���� �ķ�ʽ���أ����Ϊ40���������&��������ֵ���ݵķ�ʽ���أ����Ϊ20
		this->age += p.age;
		return *this;	//thisָ��p2��ָ�룬��*thisָ��ľ���p2���������
	}

	int age;
};

//1��������Ƴ�ͻ
void test01() {
	Person p1(10);  //p1�����вι��캯����thisָ���ָ��p1
	cout << "p1������Ϊ��" << p1.age << endl;

	Person p2(20);
	cout << "p2������Ϊ��" << p2.age << endl;
}

//2�����ض������� *this
void test02() {
	Person p1(10);

	Person p2(10);

	p2.personAddAge(p1).personAddAge(p1).personAddAge(p2);	//��ʽ���˼��

	cout << "p2������Ϊ��" << p2.age << endl;
}

int main() {

	//test01();
	test02();

	system("pause");
	return 0;
}