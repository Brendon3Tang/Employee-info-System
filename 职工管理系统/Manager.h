#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int deptID);

	void showInfo();

	string getDept();
};