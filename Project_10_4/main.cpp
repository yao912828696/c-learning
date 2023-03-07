# include "main.h"

int main() {

	//knock_table();
	
	//stars();
	
	//my_multiplication_tables();

	//int arr[] = { 2,55,3,5455,789 };
	//cout << length(arr)<<endl;
	//cout << sizeof arr / sizeof(arr[0])<<endl;
	//cout << "数组的起始空间地址为：" << int(arr) << endl;

	//char a = 'a';
	//int b = int(a);
	//int b = (int)a;
	//cout << b << endl;
	//cout << a << endl;



	//int length = sizeof arr / sizeof arr[0];
	// weight(arr,length);
	//reverse_arr_int(arr,length);
	//print_arr(arr,length);
	//bubble_sort(arr, length);

	//int a[8][9] = { {1,2},{3,4} };
	//cout << &a[0][0] << endl;
	//cout << &a[0][1] << endl;
	//cout << &a[1][0] << endl;
	//cout << &a[1][1] << endl;

	//cout << a << endl;
	//cout << a[0] << endl;
	//cout << &a[0][0] << endl;
	//cout << sizeof a << endl;
	//cout << "二维数组a所占行数为：" << sizeof a / sizeof a[0] << endl;             // 总大小 除以 每一行大小 得到  多少行
	//cout << "二维数组a所占列数为：" << sizeof a[0] / sizeof a[0][0] << endl;		// 每一行大小 除以 每一个大小 得到  多少列

	srand((unsigned int)time(NULL));



	//for (int i = 0; i < 8;i++) {
	//	int sum_i = 0;
	//	for (int j = 0;j < 9;j++) {
	//		a[i][j] = rand() % 100 + 1;
	//		cout << a[i][j] << '\t';
	//		sum_i += a[i][j];
	//	}

	//	cout << "该行的和为：" << sum_i << endl;
	//}

	//cout << "sizeof (int*) = " << sizeof(int*) << endl;            //指针在x86    即32位系统下占用4个字节
																	//在x64    即64位系统下占用8个字节
	

	//Teacher tea1 = { "tea1",{ {"qwe", 86},{"qae", 66},{"1we", 96},{"5we", 83},{"qde", 56}} };
	//Teacher tea2 = { "tea2",{ {"asdfe", 846},{"qdagae", 6456},{"13e", 9426},{"5514we", 8683},{"q2d6e", 5635}} };
	//Teacher tea3 = { "tea3",{ {"qgdae", 8256},{"qaade", 626},{"1413we", 696},{"542we", 24683},{"qdadsfe", 5656}} };
	//print_tea(&tea1);
	//print_tea(&tea2);
	//print_tea(&tea3);


	//Hero hero[5];
	//hero[0] = {"刘备", 23, 'm'};
	//hero[1] = { "关羽", 22, 'm' };
	//hero[2] = { "张飞", 20, 'm' };
	//hero[3] = { "赵云", 21, 'm' };
	//hero[4] = { "貂蝉", 19, 'w' };

	//int length = sizeof hero / sizeof hero[0];
	//print_hero_by_age(hero,length);




	// 通讯录

	Person person[MAX];
	int capacity = 0;
	int bak = 0;
	while (true) {
		menu();
		cout << "请选择：";
		int flag = 0;
		cin >> flag;
		switch (flag) {
			case 1:
				add(person, &capacity);
				break;
			case 2:
				show(person, capacity);
				break;
			case 3:
				delete_by_name(person, &capacity);
				break;
			case 4:
				find_by_name(person, capacity);
				break;
			case 5:
				update_by_name(person, capacity);
				break;
			case 6:
				if (confirm()) {
					bak = capacity;
					capacity = 0;
					cout << "已经清空全部联系人" << endl;
				}
				break;
			case 0:
				cout << "欢迎下次使用！" << endl;
				return 0;
				break;
			default: cout << "输入错误，请重新输入" << endl;
		}
		cls();
	}


	return 0;


}

