#pragma once
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

void printDeque(const deque<int>& dq) {
	for (deque<int>::const_iterator it = dq.begin();it != dq.end();it++) {
		cout << (*it) << " ";
		//*it = 5;          const_iterator   这样就不能修改了
	}
	cout << endl;
}

//deque 容器的构造 和赋值
void test01() {
	//deque 的无参构造
	deque<int> dq1;
	for (int i = 0;i < 10;i++)
		dq1.push_back(i);
	printDeque(dq1);

	// deque 的3种拷贝构造
	deque<int> dq2(dq1.begin() + 1,dq1.end() - 1);

	deque<int> dq3(10, 100);

	deque<int> dq4(dq3);

	printDeque(dq2);
	printDeque(dq3);
	printDeque(dq4);

	//  重载operator= 赋值运算符
	deque<int>dq5;
	dq5 = dq1;
	printDeque(dq5);
	// 还有 assign(begin, end)   assign(n,elem) 两种赋值操作
}


void test02() {
	deque<int> dq;
	dq.push_back(34);
	dq.push_back(24);
	dq.push_back(64);
	dq.push_back(235);
	dq.push_front(1324);
	dq.push_front(324);
	dq.push_front(3124);
	cout << "排序前 : ";
	printDeque(dq);

	// sort排序默认从小到大     支持随机访问的迭代器都可以使用sort排序
	sort(dq.begin(), dq.end());
	cout << "排序后 : ";
	printDeque(dq);
}

// 选手类
class Player {
public:
	Player(string name, int score) {
		this->name = name;
		this->score = score;
	}


public:
	string name;
	int score;
};

void creatPlayer(vector<Player>& v) {
	string name_seed = "ABCDE";
	for (int i = 0;i < 5;i++) {
		//v[i] = Player(name_seed[i], 0);  //错误的！
		string name = string("选手") + name_seed[i];        //字符串拼接时一定要统一类型 string char不完全兼容 有时会出问题
		v.push_back(Player(name, 0));
	}
}
void printResult(vector<Player>& v) {
	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
		cout << it->name << "的成绩是： " << it->score << endl;
}

void setScore(vector<Player>& v) {
	//随机数种子
	srand((unsigned int)time(NULL));
	int num = 0;
	for (vector<Player>::iterator it = v.begin(); it != v.end();it++) {

		deque<int> s;
		for (int i = 0;i < 10;i++) {
			num = rand() % 41 + 60;    //生成60~100的随机数
			s.push_back(num);
		}
		sort(s.begin(), s.end());
		s.pop_back();
		s.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = s.begin();dit != s.end();dit++)
			sum += *dit;
		int avg = sum / s.size();
		it->score = avg;
	}
}
// 评委打分案例
void test03() {

	vector<Player> v;
	creatPlayer(v);
	setScore(v);
	printResult(v);
}

void printStack(stack<int> s) {
	cout << "从栈顶到栈底的数据依次为：";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

// stack 的常用接口
void test04() {
	// stack 的构造函数   栈只有两种构造函数  一种默认构造 一种拷贝构造
	stack<int> s;
	for (int i = 0;i < 10;i++)
		s.push(i);
	printStack(s);
	s.pop();
	s.pop();
	s.pop();

	stack<int> s2(s);
	printStack(s2);

	stack<int> s3;
	s3 = s2;           //stack 的 赋值操作 重载 operator=
	printStack(s3);
}

void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
// queue 的常用接口
void test05() {
	// queue 的构造函数   队列和栈一样只有两种构造函数  一种默认构造 一种拷贝构造
	queue<int> q;
	for (int i = 0;i < 10;i++)
		q.push(10 * i);
	printQueue(q);
	q.pop();
	q.pop();
	q.pop();

	queue<int> q2(q);
	printQueue(q2);




}



//                              不能用list  作为形参对象名字？？    是的 
//void printList(const list<int>& list) {
//
//	for (list<int>::const_iterator it = list.begin();it != list.end();it++)
//		cout << *it << " ";
//	cout << endl;
//}



void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
		cout << *it << " ";
	cout << endl;
}


void test06() {
	//   list 链表的构造函数
	list<int> lst;
	for (int i = 0;i < 10;i++)
		lst.push_back(10 * i);
//	printList(lst);

	// list 链表的assign赋值  和重载 operator= 操作符
	list<int> lst2;
	lst2.assign(10,100);
	//lst2 = lst1;

	cout << "交换前:" << endl;
	printList(lst);
	printList(lst2);

	//lst.swap(lst2);
	swap(lst, lst2);
	//sort(lst.begin(), lst.end());
	cout << "交换后:" << endl;
	printList(lst);
	printList(lst2);




}
void test07() {
	list<int> L;
	for (int i = 0;i < 6;i++)
		L.push_back(rand() % 99 + 1);
	cout << "reverse 反转链表前：" << endl;
	printList(L);

	L.reverse();
	cout << "reverse 反转链表后：" << endl;
	printList(L);

	//对于迭代器不支持随机访问   （类似 it += 2 ）的容器 不能使用全局sort 
	// 但是在该容器内部会提供sort方法可以完成排序
	//默认的排序规则 从小到大
	L.sort();
	cout << "sort排序后:" << endl;
	printList(L);
	L.reverse();
	cout << "reverse 反转链表后：" << endl;
	printList(L);
}

class Person {
public:
	Person(string name, int height, int age) {
		this->name = name;
		this->height = height;
		this->age = age;
	}

public:
	string name;
	int height;
	int age;
};

void printListPerson(const list<Person>& L) {
	for (list<Person>::const_iterator it = L.begin();it != L.end();it++)
		cout << "选手的姓名：" << it->name << "\t\t身高：" << it->height << "\t年龄：" << it->age << "\t" << endl;
}

bool myCompare(Person p1, Person p2) {
	if (p1.age == p2.age) return p1.height < p2.height;
	else return p1.age < p2.age;
}
// list 容器对自定义数据类型 做排序
void test08() {
	list<Person> L;
	Person p1("ybq", 170, 19);
	Person p2("gbq", 178, 29);
	Person p3("ddq", 183, 39);
	Person p4("hbq", 184, 59);
	Person p5("zw", 164, 19);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout << "before sort:" << endl;
	printListPerson(L);
	L.sort(myCompare);
	cout << "after sort:" << endl;
	printListPerson(L);
}

void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin();it != s.end();it++)
		cout << *it << " ";
	cout << endl;
}
// set 的常用接口
void test09() {
	// set 构造只有默认构造和拷贝构造      赋值只有重载 operator=
	set<int> s1;

	// set 插入数据只有insert 没有push
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(10);

	// set 插入数据后会自动排序
	printSet(s1);


}



pair<string, int> test10() {
	//pair 的两种创建方式
	//1.   pair<string, int> p("test",1);
	//2.   pair<string, int> p = make_pair("test10", 10);
	// 通过pair   我们终于可以一次返回两个数据了！！！！
	return make_pair("test10", 10);
}


//class MyCompare
//{
//public:
//	bool operator()(int v1, int v2) {             //!!!!!!! 这个位置要加const 咋也不懂他 咋也不敢问
//		return v1 > v2;
//	}
//};
class MyCompare
{
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};

class PersonCompare {
public:
	bool operator()(const Person p1, const Person p2) const {
		if (p1.height == p2.height)
			return p1.height < p2.height;
		else
			return p1.age < p2.age;
	}
};
void test11() {
	// s1 默认的排序规则
	set<int> s1;
	s1.insert(19);
	s1.insert(39);
	s1.insert(519);
	s1.insert(1149);
	s1.insert(169);	
	printSet(s1);
	// diy s2's regular for sort
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(39);
	s2.insert(519);
	s2.insert(1149);
	s2.insert(169);
	for (set<int, MyCompare>::iterator it = s2.begin();it != s2.end();it++)
		cout << *it << " ";
	cout << endl;
	// s3 自定义数据类型的排序规则：
	// 且对于自定义数据类型，set必须指定排序规则才可以插入数据
	set<Person, PersonCompare> s3;
	Person p1("ybq", 170, 19);
	Person p2("gbq", 178, 29);
	Person p3("ddq", 183, 39);
	Person p4("hbq", 184, 59);
	Person p5("zw", 164, 19);
	s3.insert(p1);
	s3.insert(p3);
	s3.insert(p2);
	s3.insert(p4);
	s3.insert(p5);
	for (set<Person, PersonCompare>::iterator it = s3.begin();it != s3.end();it++)
		cout << "选手的姓名为：" << it->name << "\t身高：" << it->height << "\t年龄：" << it->age << endl;

	// set 中不允许相同的值出现
}
int main() {
	
	// deque 容器的构造和赋值
	//test01();

	// deque 排序
	//test02();

	// 评委打分案例
	//test03();

	// stack 的常用接口
	//test04();

	// queue 的常用接口
	//test05();

	// list 的常用接口
	//test06();

	// list 的反转和排序
	//test07();

	// list 容器对自定义数据类型 做排序
	//test08();

	// set 的常用接口
	//test09();

	// pair 对组的创建
	//cout << "pair对组的第一个数据是:" << test10().first << endl;
	//cout << "pair对组的第二个数据是:" << test10().second << endl;

	// set 自定义排序规则  ----> 通过仿函数  （类）   中 小括号operator() 的重载 完成自定义排序的逻辑
	test11();

	return 0;
}






