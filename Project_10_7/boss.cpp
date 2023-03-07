#include "boss.h"
//构造函数
Boss::Boss() {}

Boss::Boss(int id, string name) {
	m_id = id;
	m_name = name;
	m_did = 3;
}

// 重写虚函数
void Boss::showInfo() {
	cout << m_id << "\t\t " << m_name << "\t\t " << getDeptName() << endl;
}

string Boss::getDeptName() {
	return string("老板");
}