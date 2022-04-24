#include<iostream>
using namespace std;

//1������ͬ���
//����CPU��
class CPU {
public:
	//����ļ��㺯��
	virtual void caculate() = 0;
};

//�����Կ���
class VideoCard {
public:
	//�������ʾ����
	virtual void display() = 0;
};

//�����ڴ�����
class Memory {
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

//2��������
class Computer {
public:
	Computer(CPU* cpu,VideoCard* vc,Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work() {
		m_cpu->caculate();
		m_vc->display();
		m_mem->storage();
	}

	//�ṩһ����������  �ͷ�3�����������
	~Computer() {
		
		if (m_cpu != NULL || m_vc != NULL || m_mem != NULL) {
			cout << "Computer��������������" << endl;
			delete m_cpu, m_vc, m_mem;
			m_cpu = NULL;
			m_vc = NULL;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;	//CPU�����ָ��
	VideoCard* m_vc;	//�Կ������ָ��
	Memory* m_mem;	//�ڴ��������ָ��
};

//3�����峧��
//Inter����
class InterCPU :public CPU {
public:
	virtual void caculate() {
		cout << "InterCPU��ʼ������" << endl;
	}
};

class InterVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "InterVideoCard��ʼ��ʾ��" << endl;
	}
};

class InterMemory :public Memory {
public:
	virtual void storage() {
		cout << "InterMemory��ʼ�洢��" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU {
public:
	virtual void caculate() {
		cout << "LenovoCPU��ʼ������" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "LenovoVideoCard��ʼ��ʾ��" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "LenovoMemory��ʼ�洢��" << endl;
	}
};

void test01() {
	//��װ��һ̨
	//��һ̨�������
	CPU* intercpu = new InterCPU;
	VideoCard* intervc = new InterVideoCard;
	Memory* intermem = new InterMemory;

	//������һ̨����
	cout << "��һ̨���Կ�ʼ������" << endl;
	Computer* computer1 = new Computer(intercpu, intervc, intermem);
	computer1->work();
	delete computer1;

	//��װ�ڶ�̨
	//�����ڶ�̨����
	cout << "-------------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	//��װ����̨
    //��������̨����
	cout << "-------------------------" << endl;
	cout << "����̨���Կ�ʼ������" << endl;
	Computer* computer3 = new Computer(new LenovoCPU, new InterVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;

}








int main() {

	test01();

	system("pause");
	return 0;
}