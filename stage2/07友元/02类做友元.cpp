#include<iostream>
using namespace std;


class Building;
class GoodGay {

public:
	GoodGay();

	void visit();	//�ιۺ���  ����Building�е�����
	
	Building* building;
};

class Building {
	//GoodGay�� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	friend class GoodGay;

public:
	Building();

public:
	string m_settingroom;	//����

private:
	string m_bedroom;	//����
};

//����д��Ա����
GoodGay::GoodGay() {
	
	//�������������
	building = new Building;
}

void GoodGay::visit() {
	cout << "�û����� ���ڷ��ʣ�" << building->m_settingroom << endl;
	//GoodGay�� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	cout << "�û����� ���ڷ��ʣ�" << building->m_bedroom << endl;
}

Building::Building() {
	m_settingroom = "����";
	m_bedroom = "����";
}

void test01() {
	GoodGay gg;
	gg.visit();
}

int main() {

	test01();


	system("pause");
	return 0;
}