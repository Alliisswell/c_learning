#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main() {

	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1,"����",1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	//ʵ���������߶���

	WorkerManager wm;

	int choice = 0;

	while (true) {
		//����չʾ�˵���Ա����
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice) {
		case 0:  //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:  //���Ա��
			wm.addEmp();
			break;
		case 2:  //��ʾԱ��
			wm.showEmp();
			break;
		case 3:  //ɾ��Ա��
			wm.deleteEmp();
			break;
		case 4:  //�޸�Ա��
			wm.modifyEmp();
			break;
		case 5:  //����Ա��
			wm.searchEmp();
			break;
		case 6:  //����Ա��
			wm.sortEmp();
			break;
		case 7:  //����ļ�
			wm.cleanEmp();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}