#include<iostream>
using namespace std;

//��ָ����ó�Ա����

//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��

//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳�ԣ������ж�ָ���Ƿ�Ϊ�գ�

class Person {
public:

	void showClassName() {
		cout << "this is Person class" << endl;
	}

	void showPersonAge() {
		//����ԭ������Ϊ�����ָ���� NULL

		if (this == NULL) {
			return;
		}

		cout << "age= " << m_age << endl;	//ÿһ����Ա�����ڲ�����Ĭ��һ��thisָ�룬m_age === this->m_age 
	}

	int m_age = 0;
};

void test01() {
	Person* p= NULL;
	p->showClassName();
	p->showPersonAge();	//����ԭ������Ϊ�����ָ���� NULL

}

int main() {

	test01();

	system("pause");
	return 0;
}