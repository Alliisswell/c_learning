#include<iostream>
#include<string>

/*
**����������**

���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�

ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
*/

using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

void bubbleSort(Hero* heroArray, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void printHero(Hero* heroArray, int len) {
	cout <<"�����" <<endl;
	for (int i = 0; i < len; i++) {
		cout << "������" << heroArray[i].name << " ���䣺" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
}

int main8() {

	//1�����Ӣ�۽ṹ��

	//2������������5��Ӣ��
	Hero heroArray[5] =
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
		{"�ŷ�",20,"��"},
	};
	
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "����ǰ��" << endl;
	for (int i = 0; i < len; i++) {
		cout << "������" << heroArray[i].name << " ���䣺" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
	
	//3��������������򣬰������������������
	bubbleSort(heroArray, len);

	//4���������Ľ����ӡ���
	printHero(heroArray, len);

	system("pause");

	return 0;
}