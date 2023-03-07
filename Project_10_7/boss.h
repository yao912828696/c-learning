#pragma once
#include<iostream>
using namespace std;
#include "worker.h"


class Boss :public Worker {
public:
	//构造函数
	Boss();

	Boss(int id, string name);

	// 重写虚函数
	virtual void showInfo();

	virtual string getDeptName();
};
