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
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
	cout << "��ǰͨ��¼������ " << abs->m_size << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbook* abs) {
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;//������ȷ���˳�
			}
			cout << "�����������������룺" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0 && age <= 120) {
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr = addr;

		abs->m_size++;

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbook* abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "������ϵ����Ϣ���£�" << endl;
			cout << "������" << abs->personarray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personarray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
			cout << "�绰��" << abs->personarray[i].m_phone << "\t";
			cout << "��ַ��" << abs->personarray[i].m_addr << endl;
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


	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void searchPerson(Addressbook* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		cout << "��Ҫ���ҵ���ϵ��Ϊ��" << endl;
		cout << "������" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�" << (abs->personarray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personarray[ret].m_age << "\t";
		cout << "�绰��" << abs->personarray[ret].m_phone << "\t";
		cout << "��ַ��" << abs->personarray[ret].m_addr << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbook* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		cout << "��������������ϵ����Ϣ!" << endl;
		
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personarray[ret].m_name = name;
		
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;//������ȷ���˳�
			}
			cout << "�����������������룺" << endl;
		}
		
		cout << "���������䣺" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0 && age <= 120) {
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "�޸ĳɹ���" << endl;

	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(Addressbook* abs) {
	cout << "�Ƿ�ȷ���������ͨѶ¼��" << endl;
	cout << "1 --- ȷ��" << endl;
	cout << "2 --- ȡ��" << endl;
	int select=0;
	while (true) {
		cin >> select;
		if (select == 1) {
			abs->m_size = 0;
			cout << "ͨѶ¼�Ѿ���գ�" << endl;
			break;
		}
		else if (select == 2) {
			break;
		}
		else {
			cout << "����������������룺" << endl;
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
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			searchPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			clearPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
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