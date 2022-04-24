#include<iostream>
using namespace std;

/*
��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������

�����ʽ���������е�����������Ϊ**������**����**��������**

�������ʹ����������ԣ�

* ���Խ������ָ���ͷ��������
* ����Ҫ�о���ĺ���ʵ��

�������ʹ�����������

* ����Ǵ����������������ڳ����࣬�޷�ʵ��������

�������﷨��

virtual ~����(){};

���������﷨��

virtual ~����() = 0;

����::~����(){};
*/

class Animal {

public:
	Animal() {
		cout << "Animal���캯������" << endl;
	}

	//�������������Խ�� ����ָ���ͷ����������ȫ������
	//virtual ~Animal() {
	//	cout << "Animal������������" << endl;
	//}

	//��������
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;
	
	//���麯��
	virtual void speak() = 0;
};

//��������������Ҫ������������Ҳ��Ҫ������ʵ��
Animal::~Animal() {
	cout << "Animal����������������" << endl;
}

class Cat :public Animal {

public:
	Cat(string name) {
		cout << "Cat���캯������" << endl;
		m_name = new string(name);
	}

	virtual void speak() {
		cout << *m_name << "Сè��˵��" << endl;
	}

	~Cat() {
		if (m_name != NULL) {
			cout << "Cat������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	string* m_name;
};

void test01() {
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ��  ������������е�����������������������ж������ԣ������ڴ�й©
	delete animal;
}



int main() {

	test01();

	system("pause");
	return 0;
}