#include "workerManager.h"

void test() {
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三");    //父类指针接收子类对象
	//worker->showInfo();
	//delete worker;
	
	/*worker = new Manager(2, "李四");
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五");
	worker->showInfo();
	delete worker;*/
	
	exit(0);

}

int main() {
	//test();
	WorkerManager wm;

	int select = 0;
	while (true) {
		wm.showMenu();
		cout << "请输入你的选择：";
		cin >> select;
		switch (select) {
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.addWorker();
			wm.save();
			break;
		case 2: //显示职工
			wm.showWorker();
			break;
		case 3: //删除职工
			wm.deleteWorker();
			wm.save();
			break;
		case 4: //修改职工
			wm.updateWorker();
			wm.save();
			break;
		case 5: //查找职工
			wm.findWorker();
			break;
		case 6: //排序职工
			wm.sort();
			break;
		case 7: //清空文件
			wm.clean();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}




	return 0;
}