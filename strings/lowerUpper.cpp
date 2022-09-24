#include<iostream>
using namespace std;

int main(){
	// 97-122 lowercase
	// 65- 90 uppercase
	char c;
	cin >> c;
	if (c >= 92 && c <= 122){
		cout << "lowercase";
	} else if (c >= 65 && c <= 90){
		cout << "UPPERCASE";	
	} else {
		cout << "Invalid";
	}
	return 0;
}