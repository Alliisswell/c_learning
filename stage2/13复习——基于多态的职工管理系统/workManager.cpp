#include"workManager.h"


WorkerManager::WorkerManager() {
	ifstream ifs(FILENAME, ios::in);
	
	//1、文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//2、文件存在，但是为空
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	//3、文件存在，且不为空
	int num = this->getEmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_empnum = num;
	
	this->m_emparray = new Worker * [this->m_empnum];
	this->initEmpArray();
}

void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "*************  当前共有：" << this->getEmpNum() << " 名职工" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitMenu() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp() {
	cout << "请输入添加职工数量：" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//计算数组新空间大小
		int newsize = this->m_empnum + addnum;
		
		//开辟新数组
		Worker** newspace = new Worker * [newsize + 8];
		
		//将原来空间下数据，拷贝到新空间
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] = this->m_emparray[i];
			}
		}
		
		//添加新数据
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int dselect;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
		
		//释放原空间
		delete[] this->m_emparray;
		
		//更新新空间指向
		this->m_emparray = newspace;
		
		//更新新职工人数
		this->m_empnum = newsize;

		cout << "添加成功" << addnum << "名新职工！" << endl;

		this->saveFile();

		this->m_fileisempty = false;
	}
	else {
		cout << "输入有误，请重新输入：" << endl;
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
		cout << "文件不存在或者记录为空！" << endl;
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
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		int id;
		cout << "请输入要删除的职工编号：" << endl;
		cin >> id;

		int index = this->isExitEmp(id);
		if (index != -1) {
			for (int i = index; i < this->m_empnum; i++) {
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;

			this->saveFile();

			cout << "删除成功！" << endl;
		}
		else {
			cout << "该职工不存在,删除失败！" << endl;
		}

	}
	
	system("pause");
	system("cls");
}

void WorkerManager::modifyEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		int id;
		cout << "请输入要修改的职工编号：" << endl;
		cin >> id;

		int index = this->isExitEmp(id);
		if (index != -1) {
			delete this->m_emparray[index];

			int newid;
			string newname;
			int newdselect;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名：" << endl;
			cin >> newname;

			cout << "请重新选择岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

			cout << "修改成功！" << endl;

			this->saveFile();
		}
		else {
			cout << "该职工不存在，修改失败！" << endl;
		}

	}

	system("pause");
	system("cls");
}

void WorkerManager::searchEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请选择查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select;
		cin >> select;

		if (select == 1) {
			cout << "请输入要查找的职工编号：" << endl;
			int id;
			cin >> id;

			int index = this->isExitEmp(id);
			if (index != -1) {
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_emparray[index]->showInfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2) {
			cout << "请输入要查找的职工姓名：" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empnum; i++) {
				if (name == this->m_emparray[i]->m_name) {
					cout<< "查找成功，该职工信息如下：" << endl;
					this->m_emparray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else {
			cout << "输入有误!" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sortEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按照职工编号升序排列" << endl;
		cout << "2、按照职工编号降序排列" << endl;
		int select;
		cin >> select;

		//选择排序算法
		for (int i = 0; i < this->m_empnum; i++) {
			int min_or_max = i;
			for (int j = i + 1; j < this->m_empnum; j++) {
				if (select == 1) {  //升序
					if (this->m_emparray[min_or_max]->m_id > this->m_emparray[j]->m_id) {
						min_or_max = j;
					}
				}
				else {  //降序
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

	cout << "排序成功，排序结果为：" << endl;
	this->saveFile();
	this->showEmp();



}

void WorkerManager::cleanFile() {
	cout << "确认清空：" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;

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
		cout << "清空成功！" << endl;
	}
	else if (select == 2) {
		cout << "恭喜您达成三思而后行成就！" << endl;
	}
	else {
		cout << "输入有误！" << endl;
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

