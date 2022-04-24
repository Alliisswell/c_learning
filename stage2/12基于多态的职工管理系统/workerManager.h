#pragma once	//��ֹͷ�ļ��ظ�����
#include<iostream>	//��������������ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager {

public:
	
	//���캯��
	WorkerManager();	
	
	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼ְ������
	int m_empnum;

	//ְ������ָ��
	Worker** m_emparray;

	//���ְ��
	void addEmp();

	//�����ļ�
	void saveFile();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_fileisempty;

	//ͳ���ļ�������
	int getEmpNum();

	//��ʼ��ְ��
	void initEmpArray();

	//��ʾְ��
	void showEmp();

	//����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
	int isExit(int id);

	//ɾ��ְ��
	void deleteEmp();

	//�޸�ְ��
	void modifyEmp();

	//����ְ��
	void searchEmp();

	//����ְ��
	void sortEmp();

	//����ļ�
	void cleanEmp();
	
	//��������
	~WorkerManager();	

};