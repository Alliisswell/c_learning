#include<iostream>
using namespace std;

/*
��̬��Ϊ���ࣺ
* ��̬��̬���������� �� ������������ھ�̬��̬�����ú�����
* ��̬��̬����������麯��ʵ������ʱ��̬

��̬��̬�Ͷ�̬��̬����

* ��̬��̬�ĺ�����ַ���  -  ����׶�ȷ��������ַ
* ��̬��̬�ĺ�����ַ���  -  ���н׶�ȷ��������ַ
*/

class Animal {

public:
	virtual void speak() {  //�麯��
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal {
public:
	//��д�������� ����ֵ���� ������ �����б� Ҫ��ȫ��ͬ���������� ���� ��
	virtual void speak() {	//������д����ʱ��virtual ��д�ɲ�д
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal {

public:
	virtual void speak() {
		cout << "С����˵��" << endl;
	}
};


void doSpeak(Animal& animal) {	//Animal& animal = cat;
	animal.speak();
}

//ִ��˵���ĺ���
//��ַ���  �ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�����ַ���
void test01() {
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main() {

	test01();

	system("pause");
	return 0;
}

//��̬��̬������
//1���м̳й�ϵ
//2������Ҫ��д������麯��

//��̬��̬ʹ��
//�����ָ������� ָ���������

//��д����������ֵ����  ������ �����б� ��ȫһ�³�Ϊ��д

/*
#include<iostream>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/