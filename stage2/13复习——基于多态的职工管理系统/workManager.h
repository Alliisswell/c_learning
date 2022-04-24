#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "workerFile.txt"

class WorkerManager {
public:
	WorkerManager();

	void showMenu();

	void exitMenu();

	int m_empnum;

	Worker** m_emparray;

	void addEmp();

	void saveFile();

	bool m_fileisempty;

	int getEmpNum();

	void initEmpArray();

	void showEmp();

	int isExitEmp(int id);

	void deleteEmp();

	void modifyEmp();

	void searchEmp();

	void sortEmp();

	void cleanFile();

	~WorkerManager();
};