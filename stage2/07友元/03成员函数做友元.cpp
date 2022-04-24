#include<iostream>
using namespace std;

class Building;
class GoodGay {

public:
	GoodGay();

	void visit();	//��visit�������Է���Building�е�˽�г�Ա
	void visit2();	//����visit2��������Building�е�˽�г�Ա

	Building* building;

};

class Building {
	//Building��֮��� visit��Ա���� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	friend void GoodGay::visit();

public:
	Building();

public:
	string m_settingroom;	//����

private:
	string m_bedroom;	//����

};

//����ʵ�ֳ�Ա����
GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "�����Ա����visit ���ڷ��ʣ�" << building->m_settingroom << endl;
	//Building��֮��� visit��Ա���� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	cout << "�����Ա����visit ���ڷ��ʣ�" << building->m_bedroom << endl;
}

void GoodGay::visit2() {
	cout << "�����Ա����visit2 ���ڷ��ʣ�" << building->m_settingroom << endl;
	//cout << "�����Ա����visit2 ���ڷ��ʣ�" << building->m_bedroom << endl;
}

Building::Building() {
	m_settingroom = "����";
	m_bedroom = "����";
}


void test01() {
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main() {

	test01();


	system("pause");
	return 0;
}