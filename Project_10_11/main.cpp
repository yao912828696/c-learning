#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <numeric>
using namespace std;
//普通函数
void myPrint1() {       
	cout << "test1" << endl;
}

void Test1(void (*f_p)() ) {    //普通函数通过传入函数名（即该函数指针）的方式来在Test1 中调用该函数
	f_p();						//调用的方式就是 该函数指针(即传入) 加 ()
}
// 伪函数的类
class MyPrint2 { 
public:
	void operator()() {
		cout << "test2" << endl;
	}
}; 

void Test2(MyPrint2 mp) {  //伪函数通过传入函数对象(即该伪函数) 的方式来在Test2 中调用该伪函数
	mp();					//调用的方式就是 该伪函数(即传入) 加 ()
}

template<class T>
void Test3(T fn) {
	fn();				
}

void test01() {
	Test1(myPrint1);
	Test2(MyPrint2());
	Test3(myPrint1);
	Test3(MyPrint2());
}

void my_print(int value) {
	cout << value << " ";
}
class MyPrint {
public:
	void operator()(int value) {
		cout << value << " ";
	}
};

void test02() {
	vector<int> v;
	for (int i = 0;i < 10;i++)
		v.push_back(i);
	// for_each会把从区间里迭代器所取出来的数 (*it) 完整放入后面的传入中 因此容器是什么类型 就会放什么
	for_each(v.begin(), v.end(), my_print);  // 传入函数名    或者  传入伪函数对象  即传入能直接加()就能调用的那个
	for_each(v.begin(), v.end(), MyPrint());// 传入函数名    或者  传入伪函数对象  即传入能直接加()就能调用的那个

}
class Person {
public:
	Person(){
		this->name = "";
		this->age = 0;
	}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	// 使用find查找 存放自定义类型数据的容器 
	// 必须要 重载 == 以便find判断 是否相等
	bool operator==(const Person& p) {
		return this->name == p.name && this->age == p.age;
	}
	int operator+(const Person& p) {
		return this->age + p.age;
	}
	string name;
	int age;
};
void test03() {
	Person p1("ybq", 19);
	Person p2("asadgf", 29);
	Person p3("ghsd", 786);
	Person p4("qert", 75);
	Person p5("vsdf", 37);
	//p1 == p2;  不行！
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);  // find 查找
	if (it == v.end())
		cout << "can't find p2!" << endl;
	else cout << "find p2!\t" << "p2.name == " << it->name << "\tp2.age == " << it->age << endl;
	
 }
void test04() {
	vector<int> v;
	for (int i = 0;i < 6;i++) {
		v.push_back(rand() % 41 + 60);
	}
	cout << "vector<int> v 容器sort排序前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end()); 
	cout << "vector<int> v 容器sort排序后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end(),greater<int>());
	cout << "vector<int> v 容器sort排序降序后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	random_shuffle(v.begin(), v.end());
	cout << "vector<int> v 容器random_shuffle 洗牌后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	
}
void test05() {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

int main() {

	//test01();

	// for_each 遍历
	//test02();

	//test03();

	// 常用排序算法
	srand((unsigned int)time(NULL));	
	//test04();

	test05();
}
