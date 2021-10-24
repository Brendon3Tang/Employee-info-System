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
	//构造函数
	WorkerManager();

	//打印菜单
	void showMenu();

	//退出系统 （选项0）
	void exitSystem();

	//新增员工 （选项1）
	void addWorker();

	//保存员工数据，在新增员工时可用。将员工信息保存成txt文件。
	void save();

	//打印目前的系统中职工的数量
	int getNum();

	//每次进入系统时加载职工信息
	void loadWorker();

	//输出员工信息 （选项2）
	void displayWorker();

	//输入员工id后判断员工是否存在的函数
	int exist(int id);

	//删除员工 （选项3）
	void delWorker();

	//修改职工信息 （选项4）
	void modWorker();

	//查找职工 （选项5）
	void searchWorker();

	//析构函数
	~WorkerManager();

	int workerNum;
	Worker** workerArr;
	bool isEmpty;
};
