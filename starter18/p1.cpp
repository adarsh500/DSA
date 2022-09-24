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
		int n, moves = 0, smallest = INT_MAX, greatest = INT_MIN;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			greatest = max(greatest, arr[i]);
			smallest = min(smallest, arr[i]);
		}

		if (greatest - smallest == 0){
			moves = 0;
		} else {
			moves = greatest - smallest;
		}

		cout << moves << "\n";
	}	
	return 0;
}