#include"workerManager.h"

WorkerManager::WorkerManager() {
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ������ڣ�" << endl;	//���Դ���
		//��ʼ�� ��������
		this->m_empnum = 0;
		//��ʼ�� �ļ��Ƿ�Ϊ�յı�־
		this->m_fileisempty = true;
		//��ʼ�� ����ָ��
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	//2���ļ�����  ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//���Ϊ�� ��ʾ�ļ�Ϊ��
		//cout << "�ļ�Ϊ�գ�" << endl;	//���Դ���
		//��ʼ�� ��������
		this->m_empnum = 0;
		//��ʼ�� �ļ��Ƿ�Ϊ�յı�־
		this->m_fileisempty = true;
		//��ʼ�� ����ָ��
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	//3���ļ�����  ��������
	int num = this->getEmpNum();
	//cout << "ְ������Ϊ��" << num << endl;	//���Դ���
	this->m_empnum = num;

	//��������
	this->m_emparray = new Worker * [m_empnum];
	//���ļ��е����ݣ��浽������
	this->initEmpArray();

	////���Դ���
	//for (int i = 0; i < m_empnum; i++) {
	//	cout << "ְ����ţ�" << this->m_emparray[i]->m_id
	//		<< " ������" << this->m_emparray[i]->m_name
	//		<< " ���ű�ţ�" << this->m_emparray[i]->m_deptid << endl;
	//}

}

//չʾ�˵�
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
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�ٴ�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::addEmp() {
	cout << "���������ְ����������" << endl;

	int addnum = 0;	//�����û�����������
	cin >> addnum;

	if (addnum > 0) {
		//���㽫Ҫ��������Ĵ�С
		int newsize = this->m_empnum + addnum;  //�¿ռ����� = ԭ��ְ������ + ��������
		
		//����������
		Worker** newspace = new Worker * [newsize + 8];
		/*����8���±߽��ᱨ��д�뵽��newspace��ʱ���������: ��д��СΪ��newsize * 8�����ֽڣ�������д���ˡ�16�����ֽ�*/
		
		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] = this->m_emparray[i];
			}
		}

		//����������
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int selectd;

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> selectd;

			//�����û�ѡ�񴴽�ְ��
			Worker* worker = NULL;
			switch (selectd) {
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��������ְ��  ��ȷ���浽����������
			newspace[this->m_empnum + i] = worker;
			/*�ϱ� newsize ����8�����ᱨ��д�뵽��newspace��ʱ���������: ��д��СΪ��newsize * 8�����ֽڣ�������д���ˡ�16�����ֽ�*/
		}

		//�ͷ�ԭ������
		delete[] this->m_emparray;

		//����ԭ�������ָ��  ָ�򿪱�����
		this->m_emparray = newspace;

		//����ԭ������Ĵ�С  ����Ϊ��������Ĵ�С
		this->m_empnum = newsize;

		//�����ļ�
		this->saveFile();

		//����  �ļ��Ƿ�Ϊ�յı�־
		this->m_fileisempty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addnum << "����ְ����" << endl;
	}
	else {
		cout << "�������󣡣���" << endl;
	}
	//���������  �����ص���һ��Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

//��ʼ��ְ��
void WorkerManager::initEmpArray() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did == 1) {
			worker = new Employee(id,name,did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else if (did == 3) {
			worker = new Boss(id, name, did);
		}
		this->m_emparray[index] = worker;
		index++;
	}

	ifs.close();
}

//��ʾְ��
void WorkerManager::showEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_emparray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
int WorkerManager::isExit(int id) {
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++) {
		if (this->m_emparray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::deleteEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExit(id);
		if (index != -1) {	//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
			for (int i = index; i < this->m_empnum; i++) {
				this->m_emparray[i] = this->m_emparray[i+1];
			}
			this->m_empnum--;	//���������м�¼ְ������
			//ͬ�����µ��ļ���
			this->saveFile();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}

	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::modifyEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {		
		cout << "�������޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		
		int ret = this->isExit(id);
		if (ret != -1) {
			//�ҵ��������ɾ��ԭ��Ϣ
			delete this->m_emparray[ret];

			int newid = 0;
			string newname = "";
			int selectd = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "��������������" << endl;
			cin >> newname;

			cout << "��ѡ���λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> selectd;

			//�����û�ѡ�񴴽���Ӧְ����Ϣ
			Worker* worker = NULL;
			switch (selectd) {
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}

			//����ְ����ӵ��޸ĵ�ԭλ��
			this->m_emparray[ret] = worker;

			//�����ļ�
			this->saveFile();
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�����" << endl;
		}
	
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::searchEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {  //���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = this->isExit(id);
			if (ret != -1) {
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_emparray[ret]->showInfo();
			}
			else {
				cout << "���޴��ˣ�����" << endl;
			}
		}
		else if (select == 2) {  //������������
			string name;
			cout << "��������ҵ�ְ��������" << endl;
			cin >> name;

			bool flag = false;  //����һ���ҵ��ı�־���ȼٶ�û���ҵ�
			for (int i = 0; i < this->m_empnum; i++) {
				if (this->m_emparray[i]->m_name == name) {
					cout << "���ҳɹ���\t" << this->m_emparray[i]->m_id
						<< "��ְ������Ϣ���£�" << endl;

					flag = true;

					this->m_emparray[i]->showInfo();
				}
			}
			if (flag == false) {  //��־û�и��£�ȷʵû�ҵ�
				cout << "���޴��ˣ�����" << endl;
			}		
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::sortEmp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_empnum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_empnum; j++) {
				if (select == 1) {
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id) {
						minormax = j;
					}
				}
				else if(select == 2) {
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id) {
						minormax = j;
					}
				}			
			}
			if (i != minormax) {
				Worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
		}
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->saveFile();
		this->showEmp();
	}
}

//����ļ�
void WorkerManager::cleanEmp() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs;
		ofs.open(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				if (this->m_emparray[i] != NULL) {
					delete this->m_emparray[i];				
				}						
			}
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_fileisempty = true;		
		}
		cout << "��ճɹ���" << endl;
	}
	else if(select == 2) {
		cout << "��ϲ����� ��˼������ �ɾͣ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	if (this->m_emparray != NULL) {
		delete this->m_emparray;
		this->m_emparray = NULL;
	}
}