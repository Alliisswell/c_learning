#include<iostream>
#include<string>

/*
**案例描述：**

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
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
	cout <<"排序后：" <<endl;
	for (int i = 0; i < len; i++) {
		cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age << " 性别：" << heroArray[i].sex << endl;
	}
}

int main8() {

	//1、设计英雄结构体

	//2、创建数组存放5名英雄
	Hero heroArray[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
		{"张飞",20,"男"},
	};
	
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "排序前：" << endl;
	for (int i = 0; i < len; i++) {
		cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age << " 性别：" << heroArray[i].sex << endl;
	}
	
	//3、对数组进行排序，按照年龄进行升序排序
	bubbleSort(heroArray, len);

	//4、将排序后的结果打印输出
	printHero(heroArray, len);

	system("pause");

	return 0;
}