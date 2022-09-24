#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, count = 0, count1 = 0, count0 = 0;
		cin >> n >> m;
		string s = "", temp;
		for(int i = 0; i < n; i++){
			cin >> temp;
			for(int i = 0; i < temp.length(); i++){
				if(temp[i] == '1'){
					count1++;
				} else {
					count0++;
				}
			}
			if (s + temp > temp + s){
				s = temp + s;
			} else {
				s = s + temp;
			}
		}

		cout << s << endl; 

		/*
		1
		9
		23
		*/
		for(int i = 0; i < s.length(); i++){
			if (s[i] == '1'){
				count1++;
			} else {
				count += count1;
			}
		}

		cout << count << "\n";
	}
}