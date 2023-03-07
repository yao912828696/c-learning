#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILEPATH "./data.txt"

using namespace std;



// 总的功能大类


class WorkerManager {
public:

	//构造函数
	WorkerManager();

	void showMenu();
	void exitSystem();
	void showWorker();
	void addWorker();
	void save();
	int isExsit(int id);
	void deleteWorker();
	void updateWorker();
	void findWorker();
	void clean();
	int getNum();
	void init();
	void sort();
	


	//析构函数
	~WorkerManager();
public:
	int m_cap;   // 维护的   Woker* 类型 的数组的长度
	Worker** m_p;	// 维护的指针 指向堆区Woker* 类型 的数组
	bool m_fileIsEmpty;   //判断文件是否为空
};