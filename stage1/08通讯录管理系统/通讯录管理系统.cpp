//系统中需要实现的功能如下：
	//1 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
	//2 显示联系人：显示通讯录中所有联系人信息
	//3 删除联系人：按照姓名进行删除指定联系人
	//4 查找联系人：按照姓名查看指定联系人信息
	//5 修改联系人：按照姓名重新修改指定联系人
	//6 清空联系人：清空通讯录中所有信息
	//0 退出通讯录：退出当前使用的通讯录

#include<iostream>
#include<string>
#include<ctime>
#define MAX 100
using namespace std;

//设计联系人结构体
struct Person
{
	string m_Name;	//姓名
	int m_Sex;	//性别
	int m_Age;	//年龄
	string m_Phone;  //电话
	string m_Addr;	//住址
};

//设计通讯录结构体
struct Addressbooks
{
	Person personArray[MAX];
	int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
	}
	else {
		//添加姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//添加性别
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		
		while (true) {
			//如果输入1或者2可以退出循环，如果输入错误
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入性别错误，请重新输入：" << endl;
		}
		
		//添加年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true) {
			cin >> age;
			if (age > 0 && age < 120) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入年龄错误，请重新输入：" << endl;
		}
		
		//添加电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//添加地址
		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;

		cout << "已成功添加联系人！" << endl;
		
		system("pause");
		system("cls");
	}
}

//2、显示联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为0，如果为0提示记录为空，如果不为0显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << ( abs->personArray[i].m_Sex == 1 ? "男" : "女" ) << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1  通讯录  参数2  对比姓名
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3、删除指定联系人
void deletPerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人：" << endl;
	
	string name;
	cin >> name;

	//ret == -1 未查到
	//ret != -1 查到了
	int ret = isExist(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];	//逻辑删除
		}
		abs->m_Size--;
		cout << "您已成功删除联系人！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找联系人
void searchPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//修改姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//修改性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//修改年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//修改电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//修改住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "成功修改联系人！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;	//将当前记录联系人数量置0，做逻辑清空操作
	cout << "您已经成功清空所有联系人！" << endl;
	system("pause");
	system("cls");
}


//菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}



int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;	//创建用户选择输入的变量
	
	while (true) {
		//菜单调用
		showMenu();
		cin >> select;
		switch (select) {
		case 1:	//1、添加联系人
			addPerson(&abs);	//利用地址传递，可以修改实参
			break;
		case 2:	//2、显示联系人
			showPerson(&abs);
			break;
		case 3:	//3、删除联系人
		//{	//switch中每一个case下边的代码如果过多就要用 { } 括起来
		//	cout << "请输入您要删除的联系人" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		//}
			deletPerson(&abs);
			break;
		case 4:	//4、查找联系人
			searchPerson(&abs);
			break;
		case 5:	//5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:	//6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:	//0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}