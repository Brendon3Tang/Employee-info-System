#include "Manager.h"

Manager::Manager(int id, string name, int deptID)
{
	this->workerID = id;
	this->workerName = name;
	this->deptID = deptID;
}

void Manager::showInfo()
{
	cout << "职位: " << this->getDept() << endl;
	cout << "姓名: " << this->workerName << endl;
	cout << "ID: " << this->workerID << endl;
	cout << "部门ID:" << this->deptID << endl;
	cout << "职责：管理团队并且完成Boss交代的任务。" << endl;
	cout << " " << endl;
}

string Manager::getDept()
{
	return string("经理");
}
