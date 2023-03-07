#include "manager.h"
//构造函数
//Manager::Manager() {}

Manager::Manager(int id, string name) {
	m_id = id;
	m_name = name;
	m_did = 2;

}

// 重写虚函数
void Manager::showInfo() {
	cout << m_id << "\t\t " << m_name << "\t\t " << getDeptName() << endl;
}
string Manager::getDeptName() {
	return string("经理");
}