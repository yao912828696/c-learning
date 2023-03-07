#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Worker
{
public:

	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_id; //职工编号
	string m_name; //职工姓名
	int m_did;      //岗位  1-----员工    2-----经理    3-----老板   用于文件交互时岗位的判断
};