#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void subsequences(string s, string current, int i){
	if (i == s.length()){
		cout << current << " ";
		return;
	}

	subsequences(s, current, i + 1);
	subsequences(s, current + s[i], i + 1);
}

int main(){
	string s;
	cin >> s;

	subsequences(s, " ", 0);
	cout << endl << pow(2, s.length()) << endl;

}