#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int toInteger(string s, int i){
	int len = s.length();
	if (i == len){
		return 0;
	}
	int term = s[i] - '0';
	// cout << "term:" << term << endl;
	return (term * pow(10, len - i - 1)) + toInteger(s, i + 1);
}

int main(){
	string s;
	cin >> s;

	cout << toInteger(s, 0) << endl;
}