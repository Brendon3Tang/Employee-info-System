#include "Manager.h"

Manager::Manager(int id, string name, int deptID)
{
	this->workerID = id;
	this->workerName = name;
	this->deptID = deptID;
}

void Manager::showInfo()
{
	cout << "ְλ: " << this->getDept() << endl;
	cout << "����: " << this->workerName << endl;
	cout << "ID: " << this->workerID << endl;
	cout << "����ID:" << this->deptID << endl;
	cout << "ְ�𣺹����ŶӲ������Boss����������" << endl;
	cout << " " << endl;
}

string Manager::getDept()
{
	return string("����");
}
