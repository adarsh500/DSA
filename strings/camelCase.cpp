#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << s[0];
	for (int i = 1; i < s.length(); i++){
		if (isupper(s[i])){
			cout << endl;
		}

		cout << s[i];

	}
}