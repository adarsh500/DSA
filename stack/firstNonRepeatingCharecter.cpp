#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len = s.length();
	int freqArr[200] = {0};

	char firstNonRepeat;
	queue<char> q;

	for(int i = 0; i < len; i++){
		char ch = s[i];


		if (ch == q.front()){
			freqArr[ch]++;
			cout << firstNonRepeat << " ";
		}

		if(freqArr[ch] == 0){
			firstNonRepeat = ch;
			q.push(ch);
			cout << firstNonRepeat << " ";
			break;
		}
		if (q.empty()){
			cout << "-1" << " ";
		}


	}
}