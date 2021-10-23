#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0;

	virtual string getDept() = 0;

	string workerName;
	int workerID;
	int deptID;
};