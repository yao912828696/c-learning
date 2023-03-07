#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



void printMapIS(map<int, string>& m1) {
	for (map<int, string>::iterator it = m1.begin();it != m1.end();it++)
		cout << "学号：" << (*it).first << "    \t姓名：" << (*it).second << endl;
}
class Compare {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};
// map 的常用接口
void test01() {
	// map 同样只有默认构造 和拷贝构造    以及重载 operator= 操作符
	map<int, string> m1;
	pair<int, string> p1(1, "ybq");
	pair<int, string> p2(2, "dfgq");
	pair<int, string> p3(3, "gfdhdq");
	pair<int, string> p4(4, "aabq");
	pair<int, string> p5(5, "qrgs");
	m1.insert(p1);
	m1.insert(p3);
	m1.insert(p5);
	m1.insert(p4);
	m1.insert(p2);
	printMapIS(m1);
	cout << endl;
	//map 的拷贝构造
	map<int, string> m2(m1);
	printMapIS(m2);
	cout << endl;
	map<int, string>::iterator it = m2.begin();
	it++;
	m2.erase(it);
	// map 的重载operator=操作符
	map<int, string> m3;
	m3 = m2;
	printMapIS(m3);
	cout << endl;


	// map 的插入和删除
	m1.insert(make_pair(10, "japfd"));
	m1[5] = "apodjf";            //map 容器重载了operator [] 操作符    可以通过[key] 的方式创建并返回该pair<typename T1,typename T2>的引用&  value 默认为0
	//   一般不用这种方式来创建  
	printMapIS(m1);

	int key = 1;
	m1.erase(key);				//通过key来删除对应元素
	printMapIS(m1);

	map<int, string>::iterator it2 = m1.begin();
	it2++;
	m1.erase(it2);				//通过迭代器来删除对应元素
	m1.erase(m1.begin(), m1.end());  //通过迭代器区间来删除对应区间元素  都是前开后闭
	m1.clear();					//clear() 容器通用删除方法  删除所有元素
	printMapIS(m1);


	cout << "------------The divider-------------" << endl; 
	// map 的自定义排序       只对key部分排序
	map<int, string, Compare> m4;
	m4.insert(p1);
	m4.insert(p3);
	m4.insert(p5);
	m4.insert(p4);
	m4.insert(p2);
	for (map<int, string, Compare>::iterator it = m4.begin();it != m4.end();it++)
		cout << "学号：" << (*it).first << "    \t姓名：" << (*it).second << endl;
}

class Worker {
public: 
	Worker(string name, int salary) {
		this->name = name;
		this->salary = salary;
	}
	string getName() {
		return name;
	}
	int getSalary() {
		return salary;
	}
private:
	string name;
	int salary;
};

void creatWorker(vector<Worker>& v) {
	string name_seed = "ABCDEFGHIJ";
	for (int i = 0;i < 10;i++) {
		string name = "员工";
		name += name_seed[i];
		int salary = rand() % 10000 + 10000;   // 生成10000~19999;
		Worker worker(name, salary);
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++) {
		int key = rand() % 3;  // 0----策划  1----美术  2----研发
		m.insert(make_pair(key, *it));
	}
}
void showWorkerByGroup(multimap<int, Worker>& m) {

	// 先分别找到各个部门开始的迭代器
	//multimap<int, Worker>::iterator pos1 = m.find(0); 
	//multimap<int, Worker>::iterator pos2 = m.find(1);
	//multimap<int, Worker>::iterator pos3 = m.find(2);
	// 优化版本：
	multimap<int, Worker>::iterator pos1 = m.begin();
	multimap<int, Worker>::iterator pos2 = m.find(1);
	multimap<int, Worker>::iterator pos3 = m.find(2);
	if (pos2 == m.end()) pos2 = pos3;

	cout << "策划部门：" << endl;
	while (pos1 != pos2) {
		cout << "姓名：" << pos1->second.getName() << "  \t工资：" << pos1->second.getSalary() << endl;
		pos1++;
	}
	cout << "美术部门：" << endl;
	while (pos2 != pos3) {
		cout << "姓名：" << pos2->second.getName() << "  \t工资：" << pos2->second.getSalary() << endl;
		pos2++;
	}
	cout << "研发部门：" << endl;
	while (pos3 != m.end()) {
		cout << "姓名：" << pos3->second.getName() << "  \t工资：" << pos3->second.getSalary() << endl;
		pos3++;
	}

} 

void test02() {
	srand((unsigned int)time(NULL));
	vector<Worker> vWorker;
	creatWorker(vWorker);
	//测试
	for (vector<Worker>::iterator it1 = vWorker.begin();it1 != vWorker.end();it1++)
		cout << "姓名：" << it1->getName() << "  \t工资:" << it1->getSalary() << endl;
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
}

//void operator()() {
//	cout << "hello world" << endl ;        //操作符重载只能发生在类内   类外不能重载任意操作符
//}



class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	// 重载了函数调用操作符（）的类 其对象称为函数对象
	// 函数对象调用（）时 行为类似函数调用  所以函数对象也叫仿函数
	void operator()(string str) {
		cout << str << endl;
		count++;
	}

public:
	int count; //用于记录函数调用的次数
};
//仿函数是一个对象 可以说是一种数据类型
//仿函数可以有自己的状态   用其内部的成员属性来实现

void test03() {
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint函数调用了" << myPrint.count << "次" << endl;

}
#include <functional>
//negate

class Test {
public:
	Test(int n) {
		this->t = n;
	}
	int t;
};
void test04() {
	negate<int> n;
	cout << n(50) << endl;


	negate<Test> n2;

	n(Test(1));

}
int main() {

	// map 的常用接口
	//test01();

	// 员工分组
	//test02();

	// 仿函数与谓词
	//test03();

	//STL内建了一些函数对象   要引用头文件#include <functional>

	test04();


	return 0;
}