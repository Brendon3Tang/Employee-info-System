#include "Employee.h"

	Employee::Employee(int id, string name, int deptID)
	{
		this->workerID = id;
		this->workerName = name;
		this->deptID = deptID;
	}
	 
	void Employee::showInfo()
	{
		cout << "����: " << this->workerName << endl;
		cout << "ID: " << this->workerID << endl;
		cout << "����ID:" << this->deptID << endl;
		cout << "ְλ: " << this->getDept() << endl;
		cout << "ְ����ɾ�����������" << endl;
		cout << " " << endl;
	}

	string Employee::getDept()
	{
		return string("��ְͨ��");
	}
