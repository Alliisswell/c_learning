#include<iostream>
using namespace std;

//��ǳ���������Ծ������⣬Ҳ�ǳ�����һ����

//ǳ�������򵥵ĸ�ֵ���������������Կ����ڶ���ʱ��ǳ����������ظ��ͷ��ڴ�����⣬��ʱ���ȥҪ�Լ����忽�����캯����

//������ڶ�����������ռ䣬���п�������

//���⣬�����Կ����ڶ�������Ҫ�õ����������������ͷŲ���


class Person {
public:
	Person() {
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age,int height) {
		cout << "Person���вι��캯������" << endl;
		m_age = age;	
		m_height = new int(height);	 //�����Ծ��ǿ����ڶ���
	}

	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	Person(const Person& p) {
		cout << "Person�Ŀ������캯������" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;	//������Ĭ��ʵ�־������д���
		//�������
		m_height = new int(*p.m_height);  //������֮�������ڶ����ٿ����ڴ����������ֵ�������ڴ��ַ��һ��������ָ�������ֵһ��
	}

	~Person() {
		//�������룬�����������������ͷŲ���
		if (m_height!=NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "Person��������������" << endl;
	}

	int m_age = 0;	//����
	int* m_height = 0;	//���
};

void test01() {	//ջ�����ݣ��Ƚ������p2�ȱ��ͷţ�Ȼ���ͷ�p1��ʱ�����ֻ��ǳ�����ͻ����𽻲��ظ��ͷ�
	
	Person p1(18,160);
	cout << "p1������Ϊ��" << p1.m_age << "\tp1�����Ϊ��" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << "\tp2�����Ϊ��" << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//�ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������