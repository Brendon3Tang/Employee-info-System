#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;
#define FILENAME "workerFile.txt"

class WorkerManager 
{
public:
	//���캯��
	WorkerManager();

	//��ӡ�˵�
	void showMenu();

	//�˳�ϵͳ ��ѡ��0��
	void exitSystem();

	//����Ա�� ��ѡ��1��
	void addWorker();

	//����Ա�����ݣ�������Ա��ʱ���á���Ա����Ϣ�����txt�ļ���
	void save();

	//��ӡĿǰ��ϵͳ��ְ��������
	int getNum();

	//ÿ�ν���ϵͳʱ����ְ����Ϣ
	void loadWorker();

	//���Ա����Ϣ ��ѡ��2��
	void displayWorker();

	//����Ա��id���ж�Ա���Ƿ���ڵĺ���
	int exist(int id);

	//ɾ��Ա�� ��ѡ��3��
	void delWorker();

	//�޸�ְ����Ϣ ��ѡ��4��
	void modWorker();

	//����ְ�� ��ѡ��5��
	void searchWorker();

	//��������
	~WorkerManager();

	int workerNum;
	Worker** workerArr;
	bool isEmpty;
};
