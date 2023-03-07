#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:

	//构造函数
	Employee(int id, string name);

	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDeptName();
};