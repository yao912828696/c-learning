#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// 抽象出一个计算器基类   有两个操作数成员 还有一个没有任何意义的基类的 虚函数 方便进行多态
// 多态的使用条件：父类的指针或者引用指向子类对象，  子类需要重写父类的虚函数
class AbstractCaculator {
public:
	AbstractCaculator() {         //构造函数
		num1 = 10;
		num2 = 100;
	}
	virtual int getResult()	{
		return 0;
	}

public:
	int num1;
	int num2;

};

class AddCaculator :public AbstractCaculator {
	//重写父类虚函数
	int getResult() {
		return num1 + num2;
	}
};

class SubCaculator :public AbstractCaculator {
	//重写父类虚函数
	int getResult() {
		return num1 - num2;
	}
};

class MulCaculator :public AbstractCaculator {
	//重写父类虚函数
	int getResult() {
		return num1 * num2;
	}
};

class DivCaculator :public AbstractCaculator {
	//重写父类虚函数
	int getResult() {
		return num1 / num2;
	}
};

void test01() {
	//加法的多态
	AbstractCaculator* abc = new AddCaculator;  // 父类的指针或者引用指向子类对象
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //堆区开辟的数据记得使用完毕后要delete

	//减法的多态
	abc = new SubCaculator;  // 父类的指针或者引用指向子类对象
	cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //堆区开辟的数据记得使用完毕后要delete

	//乘法的多态
	abc = new MulCaculator;  // 父类的指针或者引用指向子类对象
	cout << abc->num1 << " * " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //堆区开辟的数据记得使用完毕后要delete

	//除法的多态
	abc = new DivCaculator;  // 父类的指针或者引用指向子类对象
	cout << abc->num1 << " / " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //堆区开辟的数据记得使用完毕后要delete


}




// 抽象出一个饮品制作基类   有四个没有任何意义纯虚函数 方便进行多态   抽象出了饮品制作的四个大致步骤  和一个总的制作
class MakeDrinks {
public:
	virtual void boil() = 0;
	
	virtual void brew() = 0;
	
	virtual void pour() = 0;
	
	virtual void put() = 0;

	void dowork() {
		boil();
		brew();
		pour();
		put();
	}
public:
	string drink_name = "";
};

class Coffee :public MakeDrinks {
	virtual void boil() {
		cout << "boilcoffee" << endl;
	}
	virtual void brew() {
		cout << "brewcoffee" << endl;
	}
	virtual void pour() {
		cout << "pourcoffee" << endl;
	}
	virtual void put() {
		cout << "putcoffee" << endl;
	}
};

class Tea :public MakeDrinks {
	virtual void boil() {
		cout << "boiltea" << endl;
	}
	virtual void brew() {
		cout << "brewtea" << endl;
	}
	virtual void pour() {
		cout << "pourtea" << endl;
	}
	virtual void put() {
		cout << "puttea" << endl;
	}
};

void doWork(MakeDrinks* md,string name) {
	md->dowork();
	md->drink_name = name;
	cout << "Your "<< md->drink_name << " is over!"<<endl;
	cout << "--------------------"<<endl;
	delete md;   //在堆区申请的空间记得使用完后释放

}


// 抽象出CPU基类
class CPU {
public:
	virtual void calculate() = 0;
};

// 抽象出显卡基类
class VideoCard {
public:
	virtual void display() = 0;
};

// 抽象出内存基类
class Memory {
public:
	virtual void storage() = 0;
};

// Intel 厂商的各个零件类:
class IntelCPU :public CPU {
public:
	void calculate() {
		cout << " 这是IntelCPU在使用---" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	void display() {
		cout << " 这是Intel显卡在使用---" << endl;
	}
};
class IntelMemory :public Memory {
public:
	void storage() {
		cout << " 这是Intel内存在使用---" << endl;
	}
};

// Lenovo 厂商的各个零件类:
class LenovoCPU :public CPU {
public:
	void calculate() {
		cout << " 这是LenovoCPU在使用---" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	void display() {
		cout << " 这是Lenovo显卡在使用---" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	void storage() {
		cout << " 这是Lenovo内存在使用---" << endl;
	}
};

// 电脑类
class Computer {
public:
	// 构造函数传入三个零件指针
	Computer(CPU* cpu, VideoCard* vc, Memory* mmy) {
		this->cpu = cpu;
		this->vc = vc;
		this->mmy = mmy;
	}
	// 电脑开机：
	void startUp() {
		cpu->calculate();
		vc->display();
		mmy->storage();
	}

	// 析构函数释放
	~Computer() {
		cout << "执行电脑析构函数" << endl;
		cout << "----------------------" << endl;
		delete cpu;
		delete vc;
		delete mmy;
	}
private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mmy;

};

// 电脑的组装测试
void assembly(CPU* cpu, VideoCard* vc, Memory* mmy) { // 用父类指针（或者引用 也即指针）来接收子类对象的指针 （指向子类对象） 创建多态的使用条件
	//创建电脑
	Computer computer(cpu, vc, mmy);
	// 开机
	computer.startUp();
}


// 多态的学习
//int main() {
	//  使用多态完成加减乘除计算器
	//test01();

	// 使用多态制造饮品
	//doWork(new Coffee, "coffee");
	//doWork(new Tea, "tea");
	

	// 完成三台电脑的组装测试
	/*assembly(new IntelCPU, new IntelVideoCard, new IntelMemory);
	assembly(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	assembly(new IntelCPU, new LenovoVideoCard, new IntelMemory);*/

	//return 0;
//}



// 文件操作:
int main() {
	cout << ios::in << endl;				//1             0000 0001
	cout << ios::out << endl;				//2				0000 0010
	cout << ios::ate << endl;				//4				0000 0100
	cout << ios::app << endl;			//8					0000 1000
	cout << ios::trunc << endl;			//16				0001 0000
	cout << ios::binary << endl;			//32			0010 0000
	cout << (ios::in | ios::binary) << endl;			//33        | 位或操作符在这里相当于实现了加法的操作


	// 1. 包含头文件   #include <fstream>

	// 2. 创建流对象 读、写、读写文件流对象
	ofstream ofs;    //写文件流对象   output
	//ifstream ifs;	 //读文件流对象		input
	//fstream fs;		 //读写文件流对象	output & input

	// 3. 打开文件 （根据文件路径 和 文件打开方式）  
	ofs.open("./test.txt", ios::out);
	
	// 4. 执行相应文件操作
	ofs << "This is a test!" << endl;
	ofs << "This is a test2!" << endl;
	ofs << "This is a test3!" << endl;

	// 5.执行完毕后记得关闭文件
	ofs.close();


	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	string buf;
	while (getline(ifs, buf)) {   //读取一行 不会读取换行符 \n
		cout << buf <<endl;
	};

	cout << buf << endl;
	//
	//cout << "It's over!" << endl;
	ifs.close();



	return 0;
}