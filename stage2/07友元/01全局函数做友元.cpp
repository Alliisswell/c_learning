#include<iostream>
using namespace std;

/*
�ڳ������Щ˽������ Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���

��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա

��Ԫ�Ĺؼ���Ϊ  ==friend==

��Ԫ������ʵ��

* ȫ�ֺ�������Ԫ
* ������Ԫ
* ��Ա��������Ԫ
*/

class Building {
	//goodGayȫ�ֺ��� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	friend void goodGay(Building& building);

public:
	Building() {
		m_settingroom = "����";
		m_bedroom = "����";
	}

public:
	string m_settingroom;	//����

private:
	string m_bedroom;	//����
};

void goodGay(Building& building) {
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building.m_settingroom << endl;
	//goodGayȫ�ֺ��� �� Building�� �ĺ����ѣ����Է��� Building�� �е�˽�г�Ա
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building.m_bedroom << endl;

}

void test01() {
	Building building;
	goodGay(building);
}

int main() {

	test01();


	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;





int main() {




	system("pause");
	return 0;
}
*/