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
		int n, count = 0;
		cin >> n;
		string a, b;
		cin >> a >> b;

		bool nextIsGood = false;
		for(int i = n - 1; i >= 0; i--){
			if(a[i] == b[i]){
				if (nextIsGood){
					count++;
				}
			} else {
				if (a[i] < b[i]){
					count++;
					nextIsGood = true;
				} else {
					nextIsGood = false;
				}
			}
		}

		cout << count << "\n";
	}
}