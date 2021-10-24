#include "Employee.h"

	Employee::Employee(int id, string name, int deptID)
	{
		this->workerID = id;
		this->workerName = name;
		this->deptID = deptID;
	}
	 
	void Employee::showInfo()
	{
		cout << "姓名: " << this->workerName << endl;
		cout << "ID: " << this->workerID << endl;
		cout << "部门ID:" << this->deptID << endl;
		cout << "职位: " << this->getDept() << endl;
		cout << "职责：完成经理交代的任务。" << endl;
		cout << " " << endl;
	}

	string Employee::getDept()
	{
		return string("普通职工");
	}
