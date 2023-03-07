# include "main.h"

int* test(int b) {		 // 形参数据也会存放在栈区
	int a = 11;          //局部变量存放在栈区中，栈区的数据在函数执行完后会自动释放
	cout << "在test函数中，局部变量a的地址为：" << &a <<endl;
	cout << hex << "test中输出 a：" << a <<endl;
	return &a;          // 此时外部接收到的 &a 为野指针
}
int* test1(){
	// new 开辟一个数据
	//  用()   括号里是value
	return new int(10);
}
int* test2(){
	// new 开辟一个数组
	// 用 []   括号里是数组大小
	return new int[10];
}

//int main() {
	

	//int* p = test(1);

	//在x86 32位系统下  编译器会对返回的野指针指向的内存空间做一次保留，第二次以后就是野值
	//在x64 64位系统下  编译器会在栈区的函数执行完后直接释放，不做保留

	//cout << hex << "test外部用接收到的指针访问并输出1a：" << (*p) << endl;  
	//cout << hex << "test外部用接收到的指针访问并输出2a：" << (*p) << endl;  
	

	// 使用new关键字在 自由存储区开辟空间
	//自由存储区不仅可以是堆，还可以是静态存储区   你就先当他是堆吧
	// 堆区由程序员管理  如果不释放   操作系统会在程序运行结束后回收     但是如果一直运行不释放就会造成内存泄漏


	//int* p = test1();
	//cout << *p << endl;
	////释放用delete关键字
	//delete p;
	//


	//int* arr = test2();
	//for (int i = 0;i < 10;i++) {
	//	arr[0] = i;
	//	cout << arr[0] << endl;
	//}
	//// 释放还要加上[]
	//delete[] arr;


	//实例化： （用类来创建具体的对象）
	//Circle1 c1;
	//c1.radius = 2;
	//cout << "圆的半径为：" << c1.radius << endl;
	//cout << "圆的周长为：" << c1.calculate() << endl;

	//Student s1;
	//s1.show_info();
	//s1.name = "ybq";
	//s1.num = 2021211829;
	//s1.show_info();

	//Test test;



	
	
	
	return 0;
//}