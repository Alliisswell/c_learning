#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker {

public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;	//��̬  һ���ӿڣ�������̬

	//��ȡ��λ
	virtual string getDeptName() = 0;	//��̬  һ���ӿڣ�������̬

	int m_id;  //ְ�����
	string m_name;  //ְ������
	int m_deptid;  //���ű��


};