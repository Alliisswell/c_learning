#include<iostream>

using namespace std;

#define MAX 100

struct Person {

	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;

};

struct Addressbook {

	Person personarray[MAX];
	int m_size;
};



void showMenu(Addressbook* abs) {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
	cout << "当前通信录人数： " << abs->m_size << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbook* abs) {
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;//输入正确就退出
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0 && age <= 120) {
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr = addr;

		abs->m_size++;

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbook* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "所有联系人信息如下：" << endl;
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			cout << "性别：" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
			cout << "电话：" << abs->personarray[i].m_phone << "\t";
			cout << "地址：" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExit(Addressbook* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personarray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbook* abs) {


	cout << "请输入要删除联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void searchPerson(Addressbook* abs) {
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		cout << "您要查找的联系人为：" << endl;
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		cout << "电话：" << abs->personarray[ret].m_phone << "\t";
		cout << "地址：" << abs->personarray[ret].m_addr << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbook* abs) {
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		cout << "请您重新输入联系人信息!" << endl;
		
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personarray[ret].m_name = name;
		
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;//输入正确就退出
			}
			cout << "输入有误，请重新输入：" << endl;
		}
		
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0 && age <= 120) {
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "修改成功！" << endl;

	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(Addressbook* abs) {
	cout << "是否确定清空整个通讯录？" << endl;
	cout << "1 --- 确定" << endl;
	cout << "2 --- 取消" << endl;
	int select=0;
	while (true) {
		cin >> select;
		if (select == 1) {
			abs->m_size = 0;
			cout << "通讯录已经清空！" << endl;
			break;
		}
		else if (select == 2) {
			break;
		}
		else {
			cout << "输入错误，请重新输入：" << endl;
		}

	}
	
	system("pause");
	system("cls");
}

int main() {

	Addressbook abs;
	abs.m_size = 0;


	int select = 0;

	while (true) {

		showMenu(&abs);

		cin >> select;

		switch (select) {
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			searchPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			clearPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}