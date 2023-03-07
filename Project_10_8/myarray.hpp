#pragma once
#include <string>
#include <iostream>
using namespace std;



template <class T>
class MyArray {
public:

	//构造函数
	MyArray(int cap);

	//拷贝构造
	MyArray(MyArray& arr);
	
	//尾插函数
	void PushBack(const T);
	//尾删函数
	void PopBack();

	//重载操作符=
	MyArray<T>& operator=(MyArray& arr);

	//析构函数
	~MyArray();

public:
	T* m_p;
	int m_size;
	int m_cap;
};

template <class T>
MyArray<T>::MyArray(int cap) {
	//cout << "MyArray 的构造函数调用" << endl;
	this->m_cap = cap;
	this->m_p = new T[cap];
	this->m_size = 0;
}

template <class T>
MyArray<T>::MyArray(MyArray& arr) {
	//cout << "MyArray 的拷贝构造函数调用" << endl;
	this->m_cap = arr.m_cap;
	this->m_size = arr.m_size;
	this->m_p = new T[this->m_size];
	for (int i = 0;i < this->m_size;i++) {
		this->m_p[i] = arr.m_p[i];
	}
}

template <class T>
MyArray<T>::~MyArray() {
	//cout << "MyArray 的析构函数调用" << endl;
	this->m_cap = 0;
	delete[] this->m_p;
	this->m_p = NULL;
	this->m_size = 0;
}


template <class T>
void MyArray<T>::PushBack(const T value) {
	T* temp = m_p;
	if (m_size < m_cap) {
		m_size++;
		m_p = new T[m_size];
		for (int i = 0;i < m_size - 1;i++) 
			m_p[i] = temp[i];
		m_p[m_size - 1] = value;
		delete[] temp;
		//cout << "添加成功！" << endl;
	}
	else
		cout << "容量已满" << endl;
}


template <class T>
void MyArray<T>::PopBack() {
	if (m_p)
		m_size--;
}

template <class T>
MyArray<T>& MyArray<T>::operator =(MyArray& arr) {
	if (this->m_p) {
		delete[] this->m_p;
		this->m_cap = 0;
		this->m_size = 0;
	}
	this->m_cap = arr.m_cap;
	this->m_size = arr.m_size;
	this->m_p = new T[this->m_size];
	for (int i = 0;i < this->m_size;i++) {
		this->m_p[i] = arr.m_p[i];
	}
	return *this;
}
