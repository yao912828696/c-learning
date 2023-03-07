#include <iostream>
#include <string>
using namespace std;

# define YBQ 666
int print_acsll(const char* var_name, const char var) {
	cout << var_name << " = " << var << '\n';
	cout << var_name << "的acsll码是" << int(var) << "\n";
	return 0;
}

int main() {
	// system("pause");
	const int python = 123;
	int var = 789;
	cout << "var = " << var << "\n";
	cout << "YBQ = " << YBQ << "\n";
	cout << "python = " << python << "\n";
	cout << "hello world" << endl;

	cout << "short类型所占空间为" << sizeof(short) << "个字节" << "\n";
	cout << "int类型所占空间为" << sizeof(int) << "个字节" << "\n";
	cout << "long类型所占空间为" << sizeof(long) << "个字节" << "\n";
	cout << "long long类型所占空间为" << sizeof(long long) << "个字节" << "\n";
	cout << "float类型所占空间为" << sizeof(float) << "个字节" << "\n";
	cout << "double类型所占空间为" << sizeof(double) << "个字节" << "\n";
	cout << "char类型所占空间为" << sizeof(char) << "个字节" << "\n";
	char a = 'a';
	print_acsll("aasdf", a);
	char b = 98;
	print_acsll("badf", b);
	char c = 99;
	print_acsll("cadsf", c);
	cout << '\n';
	
	string str = "hello world!!!";

	bool flag = true;
	cout << flag << '\n';
	flag = false;
	cout << flag << '\n';
	flag = 100;
	cout << flag << '\n';
	flag = -100;
	cout << flag << '\n';
	flag = 0;
	cout << flag << '\n';

	cin >> a >> b >> c >> str >> flag;
	cout << a << b << c << str << flag;
	return 0;
}