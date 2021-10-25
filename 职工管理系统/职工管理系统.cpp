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
	//Worker* employee = new Boss(1, "唐龙", 10);
	//employee->showInfo();

	WorkerManager mySystem;
	int choice;

	while (true)
	{
		mySystem.showMenu();
		cout << "请选择您需要进行的操作：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出
			mySystem.exitSystem();
			break;
		case 1://添加
			mySystem.addWorker();
			break;
		case 2://显示
			mySystem.displayWorker();
			break;
		case 3://删除
			mySystem.delWorker();
			break;
		case 4://修改
			mySystem.modWorker();
			break;
		case 5://查找
			mySystem.searchWorker();
			break;
		case 6://排序
			mySystem.sortWorker();
			break;
		case 7://清空
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