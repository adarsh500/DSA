#include <iostream>
#include <cctype>
using namespace std;

int main(){
	char ch;
	cin >> ch;
	if(isupper(ch)){
		cout << "U";
	} else if (islower(ch)){
		cout << "L";
	} else {
		cout << "I";
	}
}