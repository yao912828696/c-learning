# include "myarray.hpp"
# include <vector>

void printInt(MyArray<int>& arr) {
	for (int i = 0;i < arr.m_size;i++)
		cout << arr.m_p[i] << endl;
	cout << "-----------分割线--------" << endl;
}
void test01() {
	MyArray<int> arr1(5);
	for (int i = 0;i < arr1.m_cap;i++) {
		arr1.PushBack(i);
	}
	printInt(arr1);
	arr1.PopBack();
	//printInt(arr1);
	MyArray<int> arr2(arr1);
	arr2.PopBack();
	printInt(arr2);
	MyArray<int> arr3(arr2);
	arr3 = arr1;
	printInt(arr3);

}



void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}
void printVector2(vector<int>& v) {
	for (int i = 0;i < v.size();i++)
		cout << v[i] << " ";
	cout << endl;
}
// vector 的四种构造函数
void test02() {


	//  1. vector的无参构造            常用！
	vector<int> v1;
	int i = 0;
	//for (vector<int>::iterator it = v1.begin();it != v1.end();it++) {       
	//     这里进不去  因为是无参构造刚刚创建 还未初始化 里面为空 所以 v1.begin() == v1.end();
	//	v1.push_back(i);
	//	i++;
	//}
	for (int i = 0;i < 10;i++)
		v1.push_back(i);
	printVector(v1);

	//2.   vector的有参类似拷贝构造
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//3.  vector的有参构造  将n个elem拷贝进去 	vector<int> v3(n, elem)
	vector<int> v3(10, 100);
	printVector(v3);

	//4. vector的拷贝构造          常用！
	vector<int> v4(v3);
	printVector(v4);

	vector<int>v5;
	v5 = v1;                  //重载  operator=()  操作符
	printVector(v5);

}

void test03() {
	vector<int> v1;
	cout << "v1 is empty?" << v1.empty() << endl;
	cout << "v1's capacity = " << v1.capacity() << endl;
	cout << "v1's size = " << v1.size() << endl;
	if (v1.begin() == v1.end())
		cout << "v1.begin() == v1.end()?Yes!" << endl;
	else
		cout << "v1.begin() == v1.end()?No!" << endl;
	cout << "--------------------" << endl;
	for (int i = 0;i < 10;i++)
		v1.push_back(i);
	printVector(v1);
	cout << "--------------------" << endl;
	cout << "v1 is empty?" << v1.empty() << endl;
	cout << "v1's capacity = " << v1.capacity() << endl;
	cout << "v1's size = " << v1.size() << endl;
	if (v1.begin() == v1.end())
		cout << "v1.begin() == v1.end()?Yes!" << endl;
	else
		cout << "v1.begin() == v1.end()?No!" << endl;
}	

//vector 的插入和删除
void test04() {
	vector<int> v1;

	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	printVector(v1);

	//尾删
	v1.pop_back();
	v1.pop_back();
	printVector(v1);

	//指定位置 插入 insert
	v1.insert(v1.begin() + 1, 50);  // iterator, elem
	v1.insert(v1.begin() + 1, 3, 50);  // iterator, count, elem
	printVector(v1);

	//指定位置 删除 erase
	v1.erase(v1.end() - 2);         // iterator
	v1.erase(v1.begin() + 2, v1.end() - 2 );         // iterator_begin, iterator_end
	printVector(v1);

	//清空
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);

}

// vector 的数据存取
void test05() {
	vector<int> v1;
	v1.push_back(31);
	v1.push_back(351);
	v1.push_back(32451);
	v1.push_back(361);
	v1.push_back(321);
	v1.push_back(3221);
	v1.push_back(521);
	printVector(v1);
	printVector2(v1);

	cout << v1[3] << endl;
	cout << "v1的第一个元素为：" << v1.front() << endl;
	cout << "v1的第一个元素为：" << *v1.begin() << endl;     

	cout << "v1的最后一个元素为：" << v1.back() << endl;
	cout << "v1的最后一个元素为：" << *(v1.end()-1) << endl;
	cout << "v1的最后一个元素为：" << *(v1.rbegin())<< endl;
}
void test06() {
	vector<int> v;
	//v.reserve(100000);
	cout << "v的size：" << v.size() << "  v的capacity:" << v.capacity() << endl;

	int num = 0;
	int num2 = 0;
	int* p = NULL;
	vector<int>* p2 = NULL;
	for (int i = 0; i < 1000000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
		if (p2 != &v) {
			p2 = &v;
			num2++;
		}
	}
	cout << "v一共扩容了" << num << "次" << endl;
	cout << "v对象的地址一共改变了" << num2 << "次" << endl;

	//巧用swap()和 匿名函数创建语句完成后即销毁的特性 用来压缩 vector容器的空间
	vector<int>(v).swap(v);
	cout << "v的size：" << v.size() << "  v的capacity:" << v.capacity() << endl;

}
int main() {

	//test01();
	//string str = "1234567";
	//cout << "str.size() = " << str.size() << " sizeof str = " << sizeof str << endl;\



	//从邮箱地址获取用户名字：
	//string mail = "912828696@qq.com";
	//string user_name = mail.substr(0, mail.find("@"));
	//cout << user_name << endl;
	
	// vector 的四种构造函数
	//test02();

	//test03();

	//vector 的插入和删除
	//test04();
	
	// vector 的数据存取
	//test05();
	
	// vector 的预留空间
	//test06();
	
	
	return 0;
}