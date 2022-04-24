#include<iostream>
#include<string>
#include <windows.h>
#include <stdio.h> 

using namespace std;

//����γ���Ϣ�ṹ��
struct Courseinfo
{
	string course_name; 
	string course_addr;
};

//����γ̱�ṹ��
struct Course
{
	Courseinfo course_table[6][8];
};

//1����ӿγ�
void addCourse(Course* course) { 
	while (true) {
		cout << "���������ڣ�" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "�����뵥Ԫ��" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			cout << "���������ƣ�" << endl;
			string name;
			cin >> name;
			course->course_table[uint_id][week_id].course_name = name;

			cout << "�������ַ��" << endl;
			string addr;
			cin >> addr;
			course->course_table[uint_id][week_id].course_addr = addr;
			cout << "�ѳɹ���ӿγ̣�" << endl;
			break;
		}
		cout << "����������������룡" << endl;
	}
	
	system("pause");
	system("cls");
}

//2��ɾ���γ�
void deletCourse(Course* course) {
	while (true) {
		cout << "���������ڣ�" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "�����뵥Ԫ��" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			course->course_table[uint_id][week_id].course_name = "####";
			course->course_table[uint_id][week_id].course_addr = "###";
			cout << "�ѳɹ�ɾ���γ̣�" << endl;

			break;
		}
		cout << "����������������룡" << endl;
	}

	system("pause");
	system("cls");
}
	

//3���޸Ŀγ�
void modifyCourse(Course* course) {
	while (true) {
		cout << "���������ڣ�" << endl;
		int week_id = 0;
		cin >> week_id;

		cout << "�����뵥Ԫ��" << endl;
		int uint_id = 0;
		cin >> uint_id;

		if ((week_id > 0 && week_id < 8) && (uint_id > 0 && uint_id < 6)) {
			cout << "���������ƣ�" << endl;
			string name;
			cin >> name;
			course->course_table[uint_id][week_id].course_name = name;

			cout << "�������ַ��" << endl;
			string addr;
			cin >> addr;
			course->course_table[uint_id][week_id].course_addr = addr;
			cout << "�ѳɹ��޸Ŀγ̣�" << endl;
			break;
		}
		cout << "����������������룡" << endl;
	}

	system("pause");
	system("cls");
}

////4��ˢ�¿γ�
//void refreshCourse(Course* course) {
//	
//}

//��ʼ���γ̱�
void cinCourse(Course* course) {
	//��ʼ������һ�к͵�һ��
	course->course_table[0][0].course_name = "��Ԫ/���� ";
	course->course_table[0][0].course_addr = "";
	course->course_table[0][1].course_name = "����һ\t";
	course->course_table[0][1].course_addr = "";
	course->course_table[0][2].course_name = "���ڶ�\t";
	course->course_table[0][2].course_addr = "";
	course->course_table[0][3].course_name = "������\t";
	course->course_table[0][3].course_addr = "";
	course->course_table[0][4].course_name = "������\t";
	course->course_table[0][4].course_addr = "";
	course->course_table[0][5].course_name = "������\t";
	course->course_table[0][5].course_addr = "";
	course->course_table[0][6].course_name = "������\t";
	course->course_table[0][6].course_addr = "";
	course->course_table[0][7].course_name = "������";
	course->course_table[0][7].course_addr = "";
	course->course_table[1][0].course_name = "   һ��Ԫ";
	course->course_table[1][0].course_addr = "";
	course->course_table[2][0].course_name = "   ����Ԫ";
	course->course_table[2][0].course_addr = "";
	course->course_table[3][0].course_name = "   ����Ԫ";
	course->course_table[3][0].course_addr = "";
	course->course_table[4][0].course_name = "   �ĵ�Ԫ";
	course->course_table[4][0].course_addr = "";
	course->course_table[5][0].course_name = "   �嵥Ԫ";
	course->course_table[5][0].course_addr = "";
	//��ʼ���γ���Ϣ
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 8; j++) {
			course->course_table[i][j].course_name = "####";
			course->course_table[i][j].course_addr = "###";
		}
	}
}


//�˵�����
void showMenu(Course* course) {
	
	//ʱ��
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << "������\t" << sys.wYear << "��" << sys.wMonth << "��" << sys.wDay << "��" << "\t" << "���� " << sys.wDayOfWeek
		<< "\t    " << sys.wHour << " ʱ " << sys.wMinute << " �� " << sys.wSecond << " �� " << endl;
	//��ͷ
	cout << "��������ҵ��ѧ2020/2021ѧ���һѧ�ڿγ̱�" << endl;
	cout << "**********************************************************************************************************************************" << endl;
	
	//��ӡ�γ̱�
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			cout << course->course_table[i][j].course_name
				<< " " << course->course_table[i][j].course_addr << "\t";
		}
		cout << "\n";
		cout << endl;
	}

	cout << "**********************************************************************************************************************************" << endl;
	cout << "*****\tע�⣺���д�γ�����Ϊ�����֣�������ϢΪ��������\t*****" << endl;
	cout << "*****\t1����ӿγ�\t*****" << endl;
	cout << "*****\t2��ɾ���γ�\t*****" << endl;
	cout << "*****\t3���޸Ŀγ�\t*****" << endl;
	cout << "*****\t0���˳��γ̱�\t*****" << endl;
}
	
		
	



int main() {

	Course course;
	
	cinCourse(&course);
	
	int select = 0;
	while (true) {
		
		showMenu(&course);

		cin >> select;
		switch (select) {
		case 1:	//��ӿγ�
			addCourse(&course);
			break;
		case 2:	//ɾ���γ�
			deletCourse(&course);
			break;
		case 3:	//�޸Ŀγ�
			modifyCourse(&course);
			break;
		case 0:	//�˳��γ̱�
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
	//Sleep(10);
}