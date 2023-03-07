#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a = 0;

	cout << "Hello world!" << endl;
	//system("pause");
	vector<int> T;
	T.push_back(1);
	T.push_back(2);
	T.push_back(3);
	T.push_back(4);
	T.push_back(5);
	T.push_back(6);
	for (vector<int>::iterator it = T.begin(); it < T.end();it++) {
		cout << *it << " ";
		break;
	}
		
	return 0;
}