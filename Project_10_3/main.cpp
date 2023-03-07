#include <iostream>
#include <string>
#include <ctime>
using namespace std;


void guess_game() {
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int a = 0;
	cout << "num = " << num;
	cout << "\n请输入一个1到100的数字：";
	int count = 0;
	while (true) {
		count++;
		cin >> a;
		if (a == num) {
			cout << "恭喜你猜对了！！！" << "你一共用了" << count << "次";
			break;
		}
		else if (a > num) {
			cout << "猜大了\n";
		}
		else if (a < num) {
			cout << "猜小了\n";
		}
		cout << "重猜：";
	}
}
int judge_score(short score) {		
	if (score > 600) {
		if (score > 700) {
			cout << "你考上了清华";
		}
		else if(score > 650) {
			cout << "你考上了北大";
		}
		else {
			cout << "你考上了一本";
		}
	}
	else if (score > 500) {
		cout << "你考上了二本";
	}
	else if (score > 400) {
		cout << "你考上了三本";
	}
	else {
		cout << "你没有考上！";
	}
	cout << '\n';
	return 0;
}
void swi(short a) {
	switch (a) {
		case 1:
			cout << "今天是星期一\n";
			break;
		case 2:
			cout << "今天是星期er\n";
			break;
		case 3:
			cout << "今天是星期san\n";
			break;
		case 4:
			cout << "今天是星期si\n";
			break;
		case 5:
			cout << "今天是星期wu\n";
			break;
		case 6:
			cout << "今天是星期liu\n";
			break;
		case 7:
			cout << "relocation:";
		case 0:
			cout << "今天是星期tian\n";
			break;
		defalut:
			cout << "i don't know\n";
	}

}
int three_mi(int a) {
	return a * a * a;
}
void game2(int a) {
	int temp = a;
	int temp1 = temp % 10;
	temp /= 10;
	int temp2 = temp % 10;
	temp /= 10;
	int temp3 = temp % 10;
	int result = three_mi(temp1) + three_mi(temp2) + three_mi(temp3);
	if (result == a)
		cout << a << '\t';
}

int main() {
	short score = 0;
	// if应用
	/*cout << "请输入你的高考成绩：";
	cin >> score;
	judge_score(score);*/
	// 结束

	//int a = 6;
	//int b = 2;
	//int c = 1;
	//c = ((a > b) ? a++ : b);
	//cout << a << b << c;
	
	//short b = 7;
	//swi(b);

	// 猜数字
	//guess_game();

	//三位数水仙花数
	//int i = 153;
	//do {
	//	game2(i);
	//	i++;
	//} while (i < 1000);


	return 0;
	return 0;
	return 0;







}