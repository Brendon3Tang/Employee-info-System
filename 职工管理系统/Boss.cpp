#include "Boss.h"

Boss::Boss(int id, string name, int deptID)
{
	this->workerID = id;
	this->workerName = name;
	this->deptID = deptID;
}

void Boss::showInfo()
{
	cout << "ְλ: " << this->getDept() << endl;
	cout << "����: " << this->workerName << endl;
	cout << "ID: " << this->workerID << endl;
	cout << "����ID:" << this->deptID << endl;
	cout << "ְ�𣺹���˾��" << endl;
	cout << " " << endl;
}

string Boss::getDept()
{
	return string("�ϰ�");
}
