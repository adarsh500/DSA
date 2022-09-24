#include <iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n, count0 = 0, count1 = 0, pairs = 0;
		string s;
		cin >> n >> s;	
		for(int i = 0; i < n; i++){
			if (s[i] == '0' and s[i + 1] == '1'){
				i++;
				pairs++;
			} 
			if (s[i] == '1' and s[i + 1] == '0'){
				i++;
				pairs++;
			}
		}
		// cout << pairs << endl;
		// int pairs = min(count1, count0);
		if(pairs&1){
			cout << "Alice" << endl;
		} else {
			cout << "Bob" << endl;
		}
	}
}