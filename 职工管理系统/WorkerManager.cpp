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
	this->loadWorker();

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

//难点：创建一个指针的数组，并用指针的指针（**）来接收该数组；
/*为什么这么做？数组只能存放同一数据类型的数据，但是Employee、Manager、Boss是三种不同的数据类型，因此不能用数组直接存放。
此时利用多态：由于三种数据类型继承了同一个父类，因此可以用父类的指针数组存放这三个子类。并最后用一个指针的指针（newArr）接收这个指针数组。*/
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
	else
	{
		cout << "添加失败！" << endl;
	}

	system("pause");
	system("cls");
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

void WorkerManager::loadWorker()
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
			break;
		case 2:
			paraWorker = new Manager(paraID, paraName, paraDID);
			break;
		case 3:
			paraWorker = new Boss(paraID, paraName, paraDID);
			break;
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

int WorkerManager::exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerArr[i]->workerID == id)
			index = i;
	}
	return index;
}

void WorkerManager::delWorker()
{
	int index = -1;
	if (isEmpty)
	{
		cout << "删除失败，系统中无员工信息！" << endl;
	}
	else
	{
		int id;
		cout << "请输入需要删除的员工编号：" << endl;
		cin >> id;
		index = this->exist(id);
		if (index != -1)
		{
			for (int i = index; i < this->workerNum - 1; i++)
			{
				this->workerArr[i] = this->workerArr[i + 1];
			}
			workerNum--;
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，该员工编号不存在！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modWorker()
{
	if (isEmpty)
		cout << "系统中无职工信息！" << endl;
	else
	{
		int index = -1;
		int parID;
		cout << "请输入需要修改的员工ID：" << endl;
		cin >> parID;

		index = this->exist(parID);
		int newID;
		int newDSelect;
		string newName;

		if (index != -1) //该ID存在
		{
			Worker* newWorker = NULL;
			delete this->workerArr[index];
			cout << "请输入新的员工ID：" << endl;
			cin >> newID;
			cout << "请输入新的员工姓名：" << endl;
			cin >> newName;
			cout << "请输入新的员工职位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newDSelect;
			switch (newDSelect)
			{
			case 1:
				newWorker = new Employee(newID, newName, newDSelect);
				break;
			case 2:
				newWorker = new Manager(newID, newName, newDSelect);
				break;
			case 3:
				newWorker = new Boss(newID, newName, newDSelect);
				break;
			}
			this->workerArr[index] = newWorker;

			cout << "修改成功！" << endl;
		}
		else
			cout << "该ID不存在！" << endl;

		system("pause");
		system("cls");
	}
	


}

void WorkerManager::searchWorker()
{
	if (!isEmpty)
	{
		cout << "选择查找方式：" << endl;
		cout << "1.按ID查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select;
		cin >> select;

		if (select == 1)//用ID查找职工
		{
			cout << "请输入职工ID：" << endl;
			int searchID;
			cin >> searchID;

			int index;
			index = this->exist(searchID);
			if (index != -1)//存在
			{
				cout << "已找到ID为" << this->workerArr[index]->workerID << "的职工，该职工的信息如下：" << endl;
				this->workerArr[index]->showInfo();
			}
			else
				cout << "该ID不存在，请重新输入！" << endl;
		}
		else if (select == 2)//用姓名查找职工
		{
			cout << "请输入职工姓名：" << endl;
			string searchName;
			cin >> searchName;
			for (int i = 0; i < this->workerNum; i++)
			{
				if (this->workerArr[i]->workerName == searchName)
				{
					cout << "已找到 “" << searchName << "”(职工ID为" << this->workerArr[i]->workerID << ")的信息：" << endl;
					this->workerArr[i]->showInfo();
				}
			}
		}
		else
			cout << "输入有误，请重新输入！" << endl;
	}
	else
		cout << "系统中职工信息为空！" << endl;

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