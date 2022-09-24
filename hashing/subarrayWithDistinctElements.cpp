//NOTE: sum of lengths of distinct elements subarray starting from i 
//upto index j is :  ((j - i + 1) * (j - i + 2)) / 2;
/*
eg: arr = 1 2 3, and i = 0, j = 2

    lengths = 6
*/   

#include <bits/stdc++.h>
// #define MOD 1e9 + 7
using namespace std;
int MOD = 1000000007;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	map<int, int> m;
	int n, ans = 0;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int j = 0;
	for(int i = 0; i < n; i++){
		while(j < n and m.find(arr[j]) == m.end()){
			m[arr[j]] = 0;
			j++;
		}
		// cout << "J:" << j << "i: " << i << endl;
		ans += ((j - i) % MOD * (j - i + 1) % MOD) / 2;
		m.erase(arr[i]);
	}


	cout << ans % MOD << endl;
}