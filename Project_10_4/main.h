#include <iostream>
#include <string>
#include <ctime>

#define MAX 50
using namespace std;


// struct 结构体：
struct Student {
	string name;
	int score;
};

struct Teacher {
	string name;
	Student stu[5];
};

struct Hero {
	string name;
	int age;
	char sex;
};

void knock_table();

void stars();

void my_multiplication_tables();

int length(int arr[]);

void exchange_int(int* a, int* b);

void weight(int* arr, int length);

void reverse_arr_int(int* arr, int length);

void print_arr(int* arr, int length);

void bubble_sort(int* arr, int length);

void print_tea(const Teacher* ptea);

void print_stu(const Student* pstu);

void print_hero_by_age(Hero* hero,const int length);

void print_hero(const Hero* hero);

Hero* find_hero_by_age(Hero* hero, const int length,int age);


// 通讯录：

struct Person {
	string name;
	string sex;
	int age;
	int telephone;
	string address;
};

void menu();

void add(Person* contact, int* pcap);

void show(const Person* contact, int cap);

void delete_by_name(Person* contact, int* pcap);

Person* find_person_by_name(Person* contact, int cap, string name);

int find_person_by_name2(Person* contact, int cap, string name);

void find_by_name(Person* contact, int cap);

void update_by_name(Person* contact, int cap);

void cls();
bool confirm();



