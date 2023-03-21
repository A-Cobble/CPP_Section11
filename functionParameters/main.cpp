#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector <string> v);
void print_vector(vector <string> v);

void pass_by_value1(int num) {
	num = 1000;
}

void pass_by_value2(string s) {
	s = "Changed";
}

void pass_by_value3(vector <string> v) {
	v.clear(); // delete all vector elements
}

void print_vector(vector <string> v) {
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {

	int num{ 10 };
	int another_num{ 20 };

	cout << "num before calling pass_by_value1: " << num << endl;

	//passes in a copy of num and thus does not change num
	pass_by_value1(num);
	cout << "num after calling pass_by_value1: " << num << endl;

	cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
	pass_by_value1(another_num);
	cout << "\nanother_num after calling pass_by_value1: " << another_num << endl;

	string name{ "Alexander" };
	cout << "\nname before calling pass_by_value2: " << name << endl;
	pass_by_value2(name);
	cout << "\nname after calling pass_by_value2: " << name << endl;

	vector <string> stooges{ "Larry", "Moe", "Curly" };
	cout << "\nstooges before calling pass_by_value3: ";
	print_vector(stooges);
	pass_by_value3(stooges);
	cout << "stooges after calling pass_by_value3: ";
	print_vector(stooges);

	cout << endl;
	return 0;
}