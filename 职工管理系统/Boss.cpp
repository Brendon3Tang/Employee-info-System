#include "Boss.h"

Boss::Boss(int id, string name, int deptID)
{
	this->workerID = id;
	this->workerName = name;
	this->deptID = deptID;
}

void Boss::showInfo()
{
	cout << "职位: " << this->getDept() << endl;
	cout << "姓名: " << this->workerName << endl;
	cout << "ID: " << this->workerID << endl;
	cout << "部门ID:" << this->deptID << endl;
	cout << "职责：管理公司。" << endl;
	cout << " " << endl;
}

string Boss::getDept()
{
	return string("老板");
}
