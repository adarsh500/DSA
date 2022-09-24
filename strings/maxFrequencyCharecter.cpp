#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	// for (auto i = s.begin(); i != s.end(); i++) {

	// 	for (auto i = s.begin(); i != s.end(); i++) {

	// 	}
	// }
	char maxChar;
	int maxCount = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int count = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == c) {
				count++;
			}
			if (count > maxCount) {
				maxCount = count;
				maxChar = c;
			}
		}
	}
	cout << maxChar;
}