# include "main.h"


void knock_table() {
	for (int i = 1;i <= 100;i++) {
		bool result = (i % 10 == 7) || (i / 10) % 10 == 7 || i % 7 == 0;
		if (result)
			cout << "knock the table\n";
		else
			cout << i << '\t';
	}
}
void stars() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cout << "* ";
		}
		if (i < 9)
			cout << endl;
	}
}
void my_multiplication_tables() {
	for (int i = 1;i <= 9;i++) {
		for (int j = 1;j <= i;j++) {
			printf_s("%d * %d = %d\t", j, i, i * j);
		}
		cout << endl;
	}
}
int length(int arr[]) {
	return sizeof arr / sizeof(arr[0]);
}
void exchange_int(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void weight(int* arr, int length) {
	int max = arr[0];
	for (int i = 0;i < length - 1;i++)
		if (max < arr[i + 1])
			exchange_int(&max, &arr[i + 1]);
	cout << max;
}
void reverse_arr_int(int* arr, int length) {
	int head = 0;
	int tail = length - 1;
	while (head < tail) {
		exchange_int(&arr[head], &arr[tail]);
		head++;
		tail--;
	}
}
void print_arr(int* arr, int length) {
	for (int i = 0;i < length;i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}
void bubble_sort(int* arr, int length) {
	//cout << "原数组：";
	//print_arr(arr, length);
	for (int j = 0;j < length - 1;j++) {
		for (int i = 0;i < length - 1 - j;i++) {
			if (arr[i] > arr[i + 1])
				exchange_int(&arr[i], &arr[i + 1]);
		}
	}
	//cout << "排序后数组：";
	//print_arr(arr, length);
}
void print_stu(const Student* pstu) {
	cout << "学生名字：" << pstu->name << "成绩：" << pstu->score << endl;
}
void print_tea(const Teacher* ptea) {
	cout << "老师名字：" << ptea->name << endl;
	for (int i = 0; i < 5;i++) 
		print_stu(&(ptea->stu[i]));
	cout << endl;
}
void print_hero(const Hero* hero){
	cout << "英雄的名字:" << hero->name << "\tage:" << hero->age << "\tsex:" << hero->sex << endl;
}
Hero* find_hero_by_age(Hero* hero, const int length,int age) {
	Hero* temp = hero;
	for (int i = 0;i < length;i++) {
		if (hero[i].age == age)
			return temp;
		temp++;
	}
}
void print_hero_by_age(Hero* hero, const int length) {
	// int age[length] 人嘛了
	int age[5] = { 0 };
	for (int i = 0;i < length;i++)
		age[i] = hero[i].age;
	int len = sizeof age / sizeof age[0];
	bubble_sort(age, len);
	for (int i = 0;i < length;i++) {
		//cout << age[i] << endl;
		Hero* hr = find_hero_by_age(hero, length, age[i]);
		print_hero(hr);
	}
}

// 通讯录：
void menu() {
	cout << "****************************" << endl
		<< "********" << "1.添加联系人" << "********" << endl
		<< "********" << "2.显示联系人" << "********" << endl
		<< "********" << "3.删除联系人" << "********" << endl
		<< "********" << "4.查找联系人" << "********" << endl
		<< "********" << "5.修改联系人" << "********" << endl
		<< "********" << "6.清空联系人" << "********" << endl
		<< "********" << "0.退出通讯录" << "********" << endl
		<< "****************************" << endl;
}
void add(Person* contact, int* pcap) {
	string name;
	string sex;
	int age;
	int telephone;
	string address;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入性别：" << endl;
	cin >> sex;
	cout << "请输入年龄：" << endl;
	cin >> age;
	cout << "请输入联系电话：" << endl;
	cin >> telephone;
	cout << "请输入家庭住址：" << endl;
	cin >> address;
	contact[*pcap].name = name;
	contact[*pcap].sex = sex;
	contact[*pcap].age = age;
	contact[*pcap].telephone = telephone;
	contact[*pcap].address = address;
	(*pcap)++;
}
void show(const Person* contact, int cap) {
	if (cap == 0) {
		cout << "通讯录为空，请添加联系人" << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0;i < cap;i++) {
		cout << "姓名：" << contact[i].name << "\t性别：" << contact[i].sex << "\t年龄：" << contact[i].age << "\t联系电话："
			<< contact[i].telephone << "\t家庭住址：" << contact[i].address << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}
Person* find_person_by_name(Person* contact, int cap, string name) {
	Person* temp = contact;
	for (int i = 0;i < cap;i++) {
		if (contact[i].name == name)
			return temp;
		temp++;
	}
	cout << "没有这个人" << endl;
	return NULL;
}
int find_person_by_name2(Person* contact, int cap, string name) {
	for (int i = 0;i < cap;i++) {
		if (contact[i].name == name)
			return i;
	}
	cout << "没有这个人" << endl;
	return -1;
}
void delete_by_name(Person* contact, int* pcap) {
	string name = "";
	cout << "请输入要删除的联系人的名字：";
	cin >> name;
	int ret = find_person_by_name2(contact, *pcap, name);
	if (ret != -1) {
		if (confirm()) {
			for (int i = ret;i < (*pcap) - 1;i++)
				contact[i] = contact[i + 1];
			(*pcap)--;
			cout << "删除成功！" << endl;
		}
	}
}
void find_by_name(Person* contact, int cap) {
	string name = "";
	cout << "请输入要查找的联系人的名字：";
	cin >> name;
	Person* ps = find_person_by_name(contact, cap, name);
	if (ps) {
		cout << "姓名：" << ps->name << "\t性别：" << ps->sex << "\t年龄：" << ps->age << "\t联系电话："
			<< ps->telephone << "\t家庭住址：" << ps->address << endl;
	}
}
void update_by_name(Person* contact, int cap) {
	string name = "";
	cout << "请输入要修改的联系人的名字：";
	cin >> name;
	Person* ps = find_person_by_name(contact, cap, name);
	if (ps) {
		string name;
		string sex;
		int age;
		int telephone;
		string address;
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入性别：" << endl;
		cin >> sex;
		cout << "请输入年龄：" << endl;
		cin >> age;
		cout << "请输入联系电话：" << endl;
		cin >> telephone;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		ps->name = name;
		ps->sex = sex;
		ps->age = age;
		ps->telephone = telephone;
		ps->address = address;
	}
}
void cls() {
	system("pause");
	system("cls");
}
bool confirm() {
	string key = "";
	cout << "你确定要删除吗？确定请输入 Y ，输入其他均表示不确定" << endl;
	cin >> key;
	if (key == "Y")
		return true;
	return false;
}
