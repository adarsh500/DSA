#include <iostream>
#include <cstring>
using namespace std;

void dupChar(string str, int i) {
	if (i == str.length()){
		return;
	}

	cout << str[i];
	if (str[i] == str[i+1]){
		cout << "*";
	}

	dupChar(str, i + 1);
}

int main() {
	string str;
	cin >> str;

	dupChar(str, 0);
}