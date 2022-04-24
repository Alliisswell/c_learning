#include"workerManager.h"

WorkerManager::WorkerManager() {
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open()) {
		//cout << "文件不存在！" << endl;	//测试代码
		//初始化 数组人数
		this->m_empnum = 0;
		//初始化 文件是否为空的标志
		this->m_fileisempty = true;
		//初始化 数组指针
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	//2、文件存在  数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//如果为真 表示文件为空
		//cout << "文件为空！" << endl;	//测试代码
		//初始化 数组人数
		this->m_empnum = 0;
		//初始化 文件是否为空的标志
		this->m_fileisempty = true;
		//初始化 数组指针
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	//3、文件存在  且有数据
	int num = this->getEmpNum();
	//cout << "职工人数为：" << num << endl;	//测试代码
	this->m_empnum = num;

	//开辟数组
	this->m_emparray = new Worker * [m_empnum];
	//将文件中的数据，存到数组中
	this->initEmpArray();

	////测试代码
	//for (int i = 0; i < m_empnum; i++) {
	//	cout << "职工编号：" << this->m_emparray[i]->m_id
	//		<< " 姓名：" << this->m_emparray[i]->m_name
	//		<< " 部门编号：" << this->m_emparray[i]->m_deptid << endl;
	//}

}

//展示菜单
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
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎再次使用！" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::addEmp() {
	cout << "请输入添加职工的数量：" << endl;

	int addnum = 0;	//保存用户的输入数量
	cin >> addnum;

	if (addnum > 0) {
		//计算将要开辟数组的大小
		int newsize = this->m_empnum + addnum;  //新空间人数 = 原来职工人数 + 新增人数
		
		//开辟新数组
		Worker** newspace = new Worker * [newsize + 8];
		/*不加8，下边将会报错：写入到“newspace”时缓冲区溢出: 可写大小为“newsize * 8”个字节，但可能写入了“16”个字节*/
		
		//将原空间下内容存放到新空间下
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] = this->m_emparray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int selectd;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> selectd;

			//根据用户选择创建职工
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

			//将创建的职工  精确保存到开辟数组中
			newspace[this->m_empnum + i] = worker;
			/*上边 newsize 不加8，将会报错：写入到“newspace”时缓冲区溢出: 可写大小为“newsize * 8”个字节，但可能写入了“16”个字节*/
		}

		//释放原有数组
		delete[] this->m_emparray;

		//更改原有数组的指向  指向开辟数组
		this->m_emparray = newspace;

		//更新原有数组的大小  更改为开辟数组的大小
		this->m_empnum = newsize;

		//保存文件
		this->saveFile();

		//更新  文件是否为空的标志
		this->m_fileisempty = false;

		//提示添加成功
		cout << "成功添加" << addnum << "名新职工！" << endl;
	}
	else {
		cout << "输入有误！！！" << endl;
	}
	//按任意键后  清屏回到上一级目录
	system("pause");
	system("cls");
}

//保存文件
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

//统计文件中人数
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

//初始化职工
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

//显示职工
void WorkerManager::showEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			//利用多态调用程序接口
			this->m_emparray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
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

//删除职工
void WorkerManager::deleteEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		//按照职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExit(id);
		if (index != -1) {	//说明职工存在，并且要删除掉index位置上的职工
			for (int i = index; i < this->m_empnum; i++) {
				this->m_emparray[i] = this->m_emparray[i+1];
			}
			this->m_empnum--;	//更新数组中记录职工个数
			//同步更新到文件中
			this->saveFile();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工！" << endl;
		}

	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::modifyEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {		
		cout << "请输入修改的职工编号：" << endl;
		int id;
		cin >> id;
		
		int ret = this->isExit(id);
		if (ret != -1) {
			//找到后就立即删除原信息
			delete this->m_emparray[ret];

			int newid = 0;
			string newname = "";
			int selectd = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名：" << endl;
			cin >> newname;

			cout << "请选择岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> selectd;

			//根据用户选择创建相应职工信息
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

			//将新职工添加到修改的原位置
			this->m_emparray[ret] = worker;

			//保存文件
			this->saveFile();
		}
		else {
			cout << "修改失败！查无此人！！！" << endl;
		}
	
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::searchEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {  //按照编号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = this->isExit(id);
			if (ret != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_emparray[ret]->showInfo();
			}
			else {
				cout << "查无此人！！！" << endl;
			}
		}
		else if (select == 2) {  //按照姓名查找
			string name;
			cout << "请输入查找的职工姓名：" << endl;
			cin >> name;

			bool flag = false;  //定义一个找到的标志，先假定没有找到
			for (int i = 0; i < this->m_empnum; i++) {
				if (this->m_emparray[i]->m_name == name) {
					cout << "查找成功！\t" << this->m_emparray[i]->m_id
						<< "号职工的信息如下：" << endl;

					flag = true;

					this->m_emparray[i]->showInfo();
				}
			}
			if (flag == false) {  //标志没有更新，确实没找到
				cout << "查无此人！！！" << endl;
			}		
		}
		else {
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::sortEmp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或者记录为！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

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
		cout << "排序成功,排序后结果为：" << endl;
		this->saveFile();
		this->showEmp();
	}
}

//清空文件
void WorkerManager::cleanEmp() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;

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
		cout << "清空成功！" << endl;
	}
	else if(select == 2) {
		cout << "恭喜您达成 三思而后行 成就！" << endl;
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