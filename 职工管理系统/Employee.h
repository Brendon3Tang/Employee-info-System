#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Employee:public Worker
{
public:
	Employee(int id, string name, int deptID);

	void showInfo();

	string getDept();
};