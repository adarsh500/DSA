#include<iostream>
using namespace std;

int main(){
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++){
		int ch1 = s[i];
		int ch2 = s[i + 1];
		int diff = ch2 - ch1;
		if (i == s.length() - 1){
			cout << s[i];
		} else {
			cout << s[i] << diff;
		}
	}
}