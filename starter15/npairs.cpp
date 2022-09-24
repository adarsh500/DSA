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
		int n, count = 0;
		cin >> n;
		char s[1000000];
		cin >> s;

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j <= min(n - 1, i + 9); j++){
				if ((j - i) == abs(s[j] - s[i])){
					count++;
				}
			}
		}

		cout << count << endl;
	}

}