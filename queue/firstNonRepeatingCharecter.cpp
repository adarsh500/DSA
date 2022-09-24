#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len = s.length();
	int freqArr[26] = {0};

	char firstNonRepeat;
	queue<char> q;

	for(int i = 0; i < len; i++){
		char ch = s[i];
		q.push(ch);
		freqArr[ch - 'a']++;

		while (!q.empty()){
			if(freqArr[q.front() - 'a'] > 1){
				q.pop();
			} else {
				cout << q.front() << " ";
				break;
			}
		}

		if (q.empty()){
			cout << "-1" << " ";
		}
	}
}