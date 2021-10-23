#include "WorkerManager.h"
#include <cctype>

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.���ļ�������ʱ�������ʼ��
	if (!ifs.is_open())
	{
		this->workerNum = 0;
		this->workerArr = NULL;
		this->isEmpty = true;

		ifs.close();
		return;
	}

	//2.�ļ����ڵ���Ϊ�յ������ʼ��
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

	//3.�ļ���Ϊ�յ����
	this->workerNum = this->getNum();
	this->workerArr = new Worker * [workerNum];
	this->workerInitializer();

	//����
	//for (int i = 0; i < workerNum; i++)
	//{
	//	cout << "ID�� " << this->workerArr[i]->workerID << endl;
	//	cout << "������ " << this->workerArr[i]->workerName << endl;
	//	cout << "����ID�� " << this->workerArr[i]->deptID << endl;
	//}

}

void WorkerManager::showMenu()
{
	cout << "***********************************************************" << endl;
	cout << "******************   ְ����Ϣ����ϵͳ   ******************" << endl;
	cout << "********************  0.�˳�����ϵͳ  ********************" << endl;
	cout << "********************  1.����ְ����Ϣ  ********************" << endl;
	cout << "********************  2.��ʾְ����Ϣ  ********************" << endl;
	cout << "********************  3.ɾ��ְ����Ϣ  ********************" << endl;
	cout << "********************  4.�޸�ְ����Ϣ  ********************" << endl;
	cout << "********************  5.����ְ����Ϣ  ********************" << endl;
	cout << "********************  6.���ձ������  ********************" << endl;
	cout << "********************  7.��������ĵ�  ********************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker()
{
	cout << "����������Ա��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = workerNum + addNum;
		//int* p = new int arr[2];������
		//int* p = new int[2];���ԡ�����ʹ�õļ������ֿ�������ռ�ķ�ʽ��
		/*
		int arr[2];
		int*p =arr;   ����
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

			cout << "�������" << i + 1 << "��ְ�����" << endl;
			cin >> addID;

			cout << "�������" << i + 1 << "��ְ������" << endl;
			cin >> addName;

			cout << "�������" << i + 1 << "��ְ����λ: " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

		//���£�ְ���ļ���Ϊ��
		this->isEmpty = false;

		cout << "��ӳɹ���" << endl;

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
		cout << "ϵͳ��ְԱ��ϢΪ�գ�" << endl;
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