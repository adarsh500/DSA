#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		ll arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		ll currGcd = arr[0];
		for(int i = 1; i < n; i++){
			currGcd = gcd(currGcd, arr[i]);
			if (currGcd != arr[i]){
				cout << "-1" << "\n";
				return 0;
			} 
		}

		for(auto x : arr){
			cout << x << " ";
		}
		cout << "\n";
	}

}