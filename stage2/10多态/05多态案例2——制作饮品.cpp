#include<iostream>
using namespace std;

class AbstractDrinking {

public:
	//��ˮ
	virtual void Boil() = 0;

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;

	//���븨��
	virtual void PutSomething() = 0;

	//������Ʒ�������ӿڣ�һ���ӿڶ�����̬��
	void makeDrinking() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//����������
class Coffee:public AbstractDrinking {

public:
	//��ˮ
	virtual void Boil() {
		cout << "��ѩɽˮ" << endl;
	}

	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}

	//���뱭��
	virtual void PourInCup() {
		cout << "���뿧�ȱ�" << endl;
	}

	//���븨��
	virtual void PutSomething() {
		cout << "�����Ǻ�ţ��" << endl;
	}
};

//������Ҷ��
class Tea :public AbstractDrinking {

public:
	//��ˮ
	virtual void Boil() {
		cout << "���ˮ" << endl;
	}

	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}

	//���뱭��
	virtual void PourInCup() {
		cout << "������ɰ��" << endl;
	}

	//���븨��
	virtual void PutSomething() {
		cout << "��������˲βغ컨" << endl;
	}
};

void doWork(AbstractDrinking* abs) {
	abs->makeDrinking();
	delete abs;
}

void test01() {
	//��������
	doWork(new Coffee);
	cout << "----------------------" << endl;
	//������ˮ
	doWork(new Tea);

}


int main() {

	test01();

	system("pause");
	return 0;
}