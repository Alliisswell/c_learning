#include<iostream>
using namespace std;

//1、抽象不同零件
//抽象CPU类
class CPU {
public:
	//抽象的计算函数
	virtual void caculate() = 0;
};

//抽象显卡类
class VideoCard {
public:
	//抽象的显示函数
	virtual void display() = 0;
};

//抽象内存条类
class Memory {
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

//2、电脑类
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

	//提供一个析构函数  释放3个电脑零件、
	~Computer() {
		
		if (m_cpu != NULL || m_vc != NULL || m_mem != NULL) {
			cout << "Computer的析构函数调用" << endl;
			delete m_cpu, m_vc, m_mem;
			m_cpu = NULL;
			m_vc = NULL;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;	//CPU的零件指针
	VideoCard* m_vc;	//显卡的零件指针
	Memory* m_mem;	//内存条的零件指针
};

//3、具体厂商
//Inter厂商
class InterCPU :public CPU {
public:
	virtual void caculate() {
		cout << "InterCPU开始计算了" << endl;
	}
};

class InterVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "InterVideoCard开始显示了" << endl;
	}
};

class InterMemory :public Memory {
public:
	virtual void storage() {
		cout << "InterMemory开始存储了" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU {
public:
	virtual void caculate() {
		cout << "LenovoCPU开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "LenovoVideoCard开始显示了" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "LenovoMemory开始存储了" << endl;
	}
};

void test01() {
	//组装第一台
	//第一台电脑零件
	CPU* intercpu = new InterCPU;
	VideoCard* intervc = new InterVideoCard;
	Memory* intermem = new InterMemory;

	//创建第一台电脑
	cout << "第一台电脑开始工作！" << endl;
	Computer* computer1 = new Computer(intercpu, intervc, intermem);
	computer1->work();
	delete computer1;

	//组装第二台
	//创建第二台电脑
	cout << "-------------------------" << endl;
	cout << "第二台电脑开始工作！" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	//组装第三台
    //创建第三台电脑
	cout << "-------------------------" << endl;
	cout << "第三台电脑开始工作！" << endl;
	Computer* computer3 = new Computer(new LenovoCPU, new InterVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;

}








int main() {

	test01();

	system("pause");
	return 0;
}