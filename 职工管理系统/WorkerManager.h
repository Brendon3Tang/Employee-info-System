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
	WorkerManager();

	void showMenu();

	void exitSystem();

	void addWorker();

	void save();

	int getNum();

	void workerInitializer();

	void displayWorker();

	int exist(int id);

	void delWorker();

	~WorkerManager();

	int workerNum;
	Worker** workerArr;
	bool isEmpty;
};
