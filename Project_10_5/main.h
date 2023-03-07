#pragma once
#include <iostream>
#include <string>

#define PI 3.14f
using namespace std;

class Circle1 {
	//权限
public:
	//属性
	float radius;
	//行为 （方法）
	float calculate();
};

class Student {
public:
	string name;
	int num;

	void show_info();
};

class Test {
public:
	// 构造函数  创建对象时 编译器会自动执行这个函数  没有写默认执行空
	// 构造函数可以有参数  可以发生重载
	Test() {
		cout << "这是构造函数" << endl;
	}
	// 析构函数  在对象销毁时 编译器会自动执行这个函数  没有写默认执行空
	// 析构函数不能有参数  不可以发生重载
	~Test() {
		cout << "这是析构函数" << endl;
	}
};