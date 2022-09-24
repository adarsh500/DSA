#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	int t;
	cin >> t;
	while(t--){
		int l, n, x;
		cin >> n >> l >> x;
		int price = min(l, n - l) * x;
		cout << price << e2ndl;
	}

}