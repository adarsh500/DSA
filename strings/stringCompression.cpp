#include<iostream>
using namespace std;

int main(){
	string s;
	cin >> s;

	int i = 0;
	int j = 0;
	//string compression starts
	while (i < s.length()){
		int count = 0;
		while (j < s.length()){
			if (s[j] == s[i]){
				count++;
				j++;
			} else {
				cout << s[i] << count;
				j++;
			}
		}
		i += count;
	}


	// int i = 0, j = 0;

	// while (i < s.length()){
	// 	while (j < s.length()){
	// 		if (s[j] != s[i]){
	// 			cout << s[i] << (j - i);
	// 			i = j;
	// 		} 
	// 		j++;
	// 	}
	// }
}