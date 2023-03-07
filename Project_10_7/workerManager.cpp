#include "workerManager.h"

void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void WorkerManager::showWorker() {
	if (m_cap) {
		cout << "职工编号\t" << "职工姓名\t" << "职工岗位\t" << endl;
		cout << "--------------------------------------------------" << endl;
		for (int i = 0;i < m_cap;i++) {
			m_p[i]->showInfo();
		}
	}
	else {
		cout << "文件为空" << endl;
	}
}

void WorkerManager::addWorker() {
	//Worker** wkary
	int num = 0;
	while (true) {
		cout << "你想添加的员工的数量：";
		cin >> num;
		// 根据数量 重新开辟一个数组空间
		//m_p = new Worker * [m_cap + num];  //不能直接用m_p接收 会覆盖掉之前的数组数据 导致无法使用和无法释放
		Worker** new_p = new Worker * [m_cap + num];
		//把之前数据迁移过来
		for (int i = 0;i < m_cap;i++) {
			new_p[i] = m_p[i];
		}
		delete[] m_p;
		m_p = NULL;
		//依次添加
		if (num >= 1 && num <= 10) {
			for (int i = 0;i < num;i++) {
				int id = 0;
				string name = "";
				int dSelect = 0;

				cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
				cin >> id;


				cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
				cin >> name;


				cout << "请选择员工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1: //普通员工
					worker = new Employee(id, name);
					break;
				case 2: //经理
					worker = new Manager(id, name);
					break;
				case 3:  //老板
					worker = new Boss(id, name);
					break;
				default:
					break;
				}
				new_p[m_cap + i] = worker;

			}
			//提示信息
			cout << "成功添加" << num << "名新职工！" << endl;
			//添加完毕后更新维护信息
			m_cap += num;
			m_p = new_p;
			return;
		}
		else if (num == 0) {
			return;
		}
		else {
			cout << "输入错误，请重新输入:" << endl;
		}
	}
}

void WorkerManager::save() {
	if (m_cap) {
		ofstream ofs;
		ofs.open(FILEPATH, ios::out);
		
		for (int i = 0; i < m_cap; i++)
		{
			ofs << this->m_p[i]->m_id << " "
				<< this->m_p[i]->m_name << " "
				<< this->m_p[i]->m_did << endl;
		}
		
		ofs.close();
	}
}

int WorkerManager::isExsit(int id) {
	if (m_p)
		for (int i = 0;i < m_cap;i++) 
			if (id == m_p[i]->m_id)
				return i;
	return -1;
}  //根据员工id查找员工并返回 Worker* 指针数组下标  若没找到返回-1

void WorkerManager::deleteWorker() {
	int id = 0;
	cout << "请输入你要删除员工的编号：";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		delete m_p[index];
		for (int i = index;i < m_cap;i++) {
			m_p[index] = m_p[index + 1];
		}
		cout << "删除成功！" << endl;
		m_cap -= 1;
		return;
	}
	cout << "查无此人，删除失败" << endl;
}

void WorkerManager::findWorker() {
	int id = 0;
	cout << "请输入你要查找员工的编号：";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		cout << "员工id：" << m_p[index]->m_id
			<< "\t员工姓名：" << m_p[index]->m_name
			<< "\t员工岗位：" << m_p[index]->getDeptName()
			<< endl;
		return;
	}
	cout << "查无此人" << endl;
}

void WorkerManager::updateWorker() {
	int id = 0;
	cout << "请输入你要更新员工的编号：";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		int id = 0;
		string name = "";
		int dSelect = 0;

		cout << "请输入新职工编号：" << endl;
		cin >> id;
		cout << "请输入新职工姓名：" << endl;
		cin >> name;
		cout << "请选择员工的岗位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> dSelect;
		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1: //普通员工
			worker = new Employee(id, name);
			break;
		case 2: //经理
			worker = new Manager(id, name);
			break;
		case 3:  //老板
			worker = new Boss(id, name);
			break;
		default:
			break;
		}
		cout << "更新成功！" << endl;
		delete m_p[index];
		m_p[index] = worker;
		return;
	}
	cout << "查无此人" << endl;
}

void WorkerManager::clean() {
	string confirm = "";
	cout << "确认请输入 Y，输入其他任意键退出清空：";
	cin >> confirm;
	if (confirm == "Y") {
		if (m_p) {
			for (int i = 0;i < m_cap;i++) {
				delete m_p[i];
				m_p[i] = NULL;
			}
			delete[] m_p;
			ofstream ofs;
			ofs.open(FILEPATH, ios::trunc);
			ofs.close();
			cout << "文件清空成功！" << endl;
			return;
		}
		cout << "文件不存在或为空" << endl;
	}
}

int WorkerManager::getNum()
{
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init()
{
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	m_p = new Worker * [getNum()];
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name);
		}
		else //总裁
		{
			worker = new Boss(id, name);
		}
		//存放在数组中
		this->m_p[index] = worker;
		index++;
	}
	m_cap = index;
}

// sort
//排序职工
void WorkerManager::sort()
{
	if (m_cap==0)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_cap; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_cap; j++)
			{
				if (select == 1) //升序
				{
					if (m_p[minOrMax]->m_id > m_p[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_p[minOrMax]->m_id < m_p[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_p[i];
				m_p[i] = m_p[minOrMax];
				m_p[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->showWorker();
	}

}
//构造函数
WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_cap = 0;  //初始化人数
		this->m_fileIsEmpty = true; //初始化文件为空标志
		this->m_p = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	
	
	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_cap = 0;
		this->m_fileIsEmpty = true;
		this->m_p = NULL;
		ifs.close();
		return;
	}
	
	
	//文件存在，且有记录
	init();

}

//析构函数
WorkerManager::~WorkerManager(){
	if (m_p) {
		for (int i = 0;i < m_cap;i++) {
			delete m_p[i];
			m_p[i] = NULL;
		}
		delete[] m_p;
	}
}
