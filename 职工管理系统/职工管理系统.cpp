#include "WorkerManager.h"
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main()
{
	////test
	//Worker* employee = new Boss(1, "����", 10);
	//employee->showInfo();

	WorkerManager mySystem;
	int choice;

	while (true)
	{
		mySystem.showMenu();
		cout << "��ѡ������Ҫ���еĲ�����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�
			mySystem.exitSystem();
			break;
		case 1://���
			mySystem.addWorker();
			break;
		case 2://��ʾ
			mySystem.displayWorker();
			break;
		case 3://ɾ��
			mySystem.delWorker();
			break;
		case 4://�޸�
			mySystem.modWorker();
			break;
		case 5://����
			mySystem.searchWorker();
			break;
		case 6://����
			mySystem.sortWorker();
			break;
		case 7://���
			mySystem.clearAll();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}