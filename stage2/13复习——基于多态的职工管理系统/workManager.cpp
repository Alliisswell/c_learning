#include"workManager.h"


WorkerManager::WorkerManager() {
	ifstream ifs(FILENAME, ios::in);
	
	//1���ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//2���ļ����ڣ�����Ϊ��
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ��Ҳ�Ϊ��
	int num = this->getEmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_empnum = num;
	
	this->m_emparray = new Worker * [this->m_empnum];
	this->initEmpArray();
}

void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "*************  ��ǰ���У�" << this->getEmpNum() << " ��ְ��" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitMenu() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp() {
	cout << "���������ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//���������¿ռ��С
		int newsize = this->m_empnum + addnum;
		
		//����������
		Worker** newspace = new Worker * [newsize + 8];
		
		//��ԭ���ռ������ݣ��������¿ռ�
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] = this->m_emparray[i];
			}
		}
		
		//���������
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int dselect;

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			default:
				break;
			}

			newspace[this->m_empnum + i] = worker;
		}
		
		//�ͷ�ԭ�ռ�
		delete[] this->m_emparray;
		
		//�����¿ռ�ָ��
		this->m_emparray = newspace;
		
		//������ְ������
		this->m_empnum = newsize;

		cout << "��ӳɹ�" << addnum << "����ְ����" << endl;

		this->saveFile();

		this->m_fileisempty = false;
	}
	else {
		cout << "�����������������룺" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs(FILENAME, ios::out);
	
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << "  "
			<< this->m_emparray[i]->m_name << "\t"
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum() {
	ifstream ifs(FILENAME,ios::in);

	int id;
	string name;
	int deptid;

	int num=0;
	while (ifs >> id && ifs >> name && ifs >> deptid) {
		num++;
	}
	return num;
}

void WorkerManager::initEmpArray() {
	ifstream ifs(FILENAME,ios::in);

	int id;
	string name;
	int deptid;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid) {
		Worker* worker = NULL;
		if (deptid == 1) {
			worker = new Employee(id, name, deptid);
		}
		if (deptid == 2) {
			worker = new Manager(id, name, deptid);
		}
		if (deptid == 3) {
			worker = new Boss(id, name, deptid);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_empnum; i++) {
			this->m_emparray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isExitEmp(int id) {
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++) {
		if (id == this->m_emparray[i]->m_id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		int id;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;

		int index = this->isExitEmp(id);
		if (index != -1) {
			for (int i = index; i < this->m_empnum; i++) {
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;

			this->saveFile();

			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "��ְ��������,ɾ��ʧ�ܣ�" << endl;
		}

	}
	
	system("pause");
	system("cls");
}

void WorkerManager::modifyEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		int id;
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		cin >> id;

		int index = this->isExitEmp(id);
		if (index != -1) {
			delete this->m_emparray[index];

			int newid;
			string newname;
			int newdselect;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "��������������" << endl;
			cin >> newname;

			cout << "������ѡ���λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newdselect;

			Worker* worker = NULL;
			switch (newdselect)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 1);
				break;
			case 3:
				worker = new Boss(newid, newname, 1);
				break;
			default:
				break;
			}

			this->m_emparray[index] = worker;

			cout << "�޸ĳɹ���" << endl;

			this->saveFile();
		}
		else {
			cout << "��ְ�������ڣ��޸�ʧ�ܣ�" << endl;
		}

	}

	system("pause");
	system("cls");
}

void WorkerManager::searchEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ����ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select;
		cin >> select;

		if (select == 1) {
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int id;
			cin >> id;

			int index = this->isExitEmp(id);
			if (index != -1) {
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_emparray[index]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) {
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empnum; i++) {
				if (name == this->m_emparray[i]->m_name) {
					cout<< "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->m_emparray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "��������!" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sortEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������ְ�������������" << endl;
		cout << "2������ְ����Ž�������" << endl;
		int select;
		cin >> select;

		//ѡ�������㷨
		for (int i = 0; i < this->m_empnum; i++) {
			int min_or_max = i;
			for (int j = i + 1; j < this->m_empnum; j++) {
				if (select == 1) {  //����
					if (this->m_emparray[min_or_max]->m_id > this->m_emparray[j]->m_id) {
						min_or_max = j;
					}
				}
				else {  //����
					if (this->m_emparray[min_or_max]->m_id < this->m_emparray[j]->m_id) {
						min_or_max = j;
					}
				}

			}
			if (i != min_or_max) {
				Worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[min_or_max];
				this->m_emparray[min_or_max] = temp;
			}
		}
	}

	cout << "����ɹ���������Ϊ��" << endl;
	this->saveFile();
	this->showEmp();



}

void WorkerManager::cleanFile() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				if (this->m_emparray[i] != NULL) {
					delete this->m_emparray[i];
				}
			}
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_fileisempty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	else if (select == 2) {
		cout << "��ϲ�������˼�����гɾͣ�" << endl;
	}
	else {
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	if (this->m_emparray != NULL) {
		for (int i = 0; i < this->m_empnum; i++) {
			if (this->m_emparray[i] != NULL) {
				delete this->m_emparray[i];
			}
		}
		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}
}

