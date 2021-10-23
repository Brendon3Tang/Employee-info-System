#include "WorkerManager.h"
#include <cctype>

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.当文件不存在时的情况初始化
	if (!ifs.is_open())
	{
		this->workerNum = 0;
		this->workerArr = NULL;
		this->isEmpty = true;

		ifs.close();
		return;
	}

	//2.文件存在但是为空的情况初始化
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->workerNum = 0;
		this->workerArr = NULL;
		this->isEmpty = true;

		ifs.close();
		return;
	}

	//3.文件不为空的情况
	this->workerNum = this->getNum();
	this->workerArr = new Worker * [workerNum];
	this->workerInitializer();

	//测试
	//for (int i = 0; i < workerNum; i++)
	//{
	//	cout << "ID： " << this->workerArr[i]->workerID << endl;
	//	cout << "姓名： " << this->workerArr[i]->workerName << endl;
	//	cout << "部门ID： " << this->workerArr[i]->deptID << endl;
	//}

}

void WorkerManager::showMenu()
{
	cout << "***********************************************************" << endl;
	cout << "******************   职工信息管理系统   ******************" << endl;
	cout << "********************  0.退出管理系统  ********************" << endl;
	cout << "********************  1.增加职工信息  ********************" << endl;
	cout << "********************  2.显示职工信息  ********************" << endl;
	cout << "********************  3.删除职工信息  ********************" << endl;
	cout << "********************  4.修改职工信息  ********************" << endl;
	cout << "********************  5.查找职工信息  ********************" << endl;
	cout << "********************  6.按照编号排序  ********************" << endl;
	cout << "********************  7.清空所有文档  ********************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker()
{
	cout << "请输入新增员工的数量" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = workerNum + addNum;
		//int* p = new int arr[2];不可以
		//int* p = new int[2];可以。本次使用的即是这种开辟数组空间的方式。
		/*
		int arr[2];
		int*p =arr;   可以
		*/
		Worker** newArr = new Worker* [newSize];
		
		if (this->workerArr != NULL)
		{
			for (int i = 0; i < this->workerNum; i++)
				newArr[i] = this->workerArr[i];
		}

		for (int i = 0; i < addNum; i++)
		{
			int addID;
			int dSelect;
			string addName;

			cout << "请输入第" << i + 1 << "个职工编号" << endl;
			cin >> addID;

			cout << "请输入第" << i + 1 << "个职工姓名" << endl;
			cin >> addName;

			cout << "请输入第" << i + 1 << "个职工岗位: " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* newWorker = NULL;
			switch (dSelect)
			{
			case 1:
				newWorker = new Employee(addID, addName, 1);
				break;
			case 2:
				newWorker = new Manager(addID, addName, 2);
				break;
			case 3:
				newWorker = new Boss(addID, addName, 3);
				break;
			}

			newArr[this->workerNum + i] = newWorker;
		}

		delete[] this->workerArr;

		this->workerArr = newArr;

		this->workerNum = newSize;

		//更新：职工文件不为空
		this->isEmpty = false;

		cout << "添加成功！" << endl;

		this->save();
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->workerNum; i++)
	{
		ofs << this->workerArr[i]->workerID << " "
			<< this->workerArr[i]->workerName << " "
			<< this->workerArr[i]->deptID << " " << endl;
	}
	ofs.close();
}

int WorkerManager::getNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int paraID;
	int paraDID;
	int paraNum = 0;
	string paraName;

	while (ifs >> paraID && ifs >> paraName && ifs >> paraDID)
	{
		paraNum++;
	}

	ifs.close();

	return paraNum;
}

void WorkerManager::workerInitializer()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int paraID;
	int paraDID;
	string paraName;
	int index = 0;
	
	Worker* paraWorker = NULL;
	while (ifs >> paraID && ifs >> paraName && ifs >> paraDID)
	{
		switch (paraDID)
		{
		case 1:
			paraWorker = new Employee(paraID, paraName, paraDID);
		case 2:
			paraWorker = new Manager(paraID, paraName, paraDID);
		case 3:
			paraWorker = new Boss(paraID, paraName, paraDID);
		}
		this->workerArr[index] = paraWorker;
		index++;
		
	}

	ifs.close();
}

void WorkerManager::displayWorker()
{
	if (this->isEmpty)
	{
		cout << "系统中职员信息为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->workerNum; i++)
		{
			this->workerArr[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->workerArr != NULL)
	{
		delete[] this->workerArr;
		this->workerArr = NULL;
	}
}