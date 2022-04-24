//ϵͳ����Ҫʵ�ֵĹ������£�
	//1 �����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1000��
	//2 ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
	//3 ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
	//4 ������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
	//5 �޸���ϵ�ˣ��������������޸�ָ����ϵ��
	//6 �����ϵ�ˣ����ͨѶ¼��������Ϣ
	//0 �˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼

#include<iostream>
#include<string>
#include<ctime>
#define MAX 100
using namespace std;

//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;	//����
	int m_Sex;	//�Ա�
	int m_Age;	//����
	string m_Phone;  //�绰
	string m_Addr;	//סַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	Person personArray[MAX];
	int m_Size;
};

//1�������ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else {
		//�������
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//����Ա�
		int sex=0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		
		while (true) {
			//�������1����2�����˳�ѭ��������������
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����Ա�������������룺" << endl;
		}
		
		//�������
		int age = 0;
		cout << "���������䣺" << endl;
		while (true) {
			cin >> age;
			if (age > 0 && age < 120) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "��������������������룺" << endl;
		}
		
		//��ӵ绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ӵ�ַ
		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "�ѳɹ������ϵ�ˣ�" << endl;
		
		system("pause");
		system("cls");
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0��ʾ��¼Ϊ�գ������Ϊ0��ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << ( abs->personArray[i].m_Sex == 1 ? "��" : "Ů" ) << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1  ͨѶ¼  ����2  �Ա�����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3��ɾ��ָ����ϵ��
void deletPerson(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	
	string name;
	cin >> name;

	//ret == -1 δ�鵽
	//ret != -1 �鵽��
	int ret = isExist(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];	//�߼�ɾ��
		}
		abs->m_Size--;
		cout << "���ѳɹ�ɾ����ϵ�ˣ�" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//4��������ϵ��
void searchPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//�޸�����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�޸��Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//�޸�����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�޸ĵ绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//�޸�סַ
		string address;
		cout << "������סַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�ɹ��޸���ϵ�ˣ�" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;	//����ǰ��¼��ϵ��������0�����߼���ղ���
	cout << "���Ѿ��ɹ����������ϵ�ˣ�" << endl;
	system("pause");
	system("cls");
}


//�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}



int main() {

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;	//�����û�ѡ������ı���
	
	while (true) {
		//�˵�����
		showMenu();
		cin >> select;
		switch (select) {
		case 1:	//1�������ϵ��
			addPerson(&abs);	//���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:	//2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:	//3��ɾ����ϵ��
		//{	//switch��ÿһ��case�±ߵĴ�����������Ҫ�� { } ������
		//	cout << "��������Ҫɾ������ϵ��" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
		//}
			deletPerson(&abs);
			break;
		case 4:	//4��������ϵ��
			searchPerson(&abs);
			break;
		case 5:	//5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:	//6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:	//0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
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