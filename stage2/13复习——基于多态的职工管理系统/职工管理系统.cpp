#include<iostream>
using namespace std;
#include"workManager.h"


int main() {

	WorkerManager wm;

	int select = 0;

	while (true)
	{
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 0://0.�˳��������
			wm.exitMenu();
			break;
		case 1://1.����ְ����Ϣ
			wm.addEmp();
			break;
		case 2://2.��ʾְ����Ϣ
			wm.showEmp();
			break;
		case 3://3.ɾ��ְ����Ϣ������ְ����ţ�
			wm.deleteEmp();
			break;
		case 4://4.�޸�ְ����Ϣ������ְ����ţ�
			wm.modifyEmp();
			break;
		case 5://5.����ְ����Ϣ
			wm.searchEmp();
			break;
		case 6://6.���ձ������
			wm.sortEmp();
			break;
		case 7://7.��������ĵ�
			wm.cleanFile();
			break;
		default:
			cout << "�����������������룺" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}


