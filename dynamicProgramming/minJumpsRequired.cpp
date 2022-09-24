#include <bits/stdc++.h>
using namespace std;

// int minJumps(int arr[], int k, int n){
// 	if (k == n){
// 		return 0;
// 	}

// 	if (arr[k] == 0){
// 		return INT_MAX;
// 	}

// 	int minJump = INT_MAX;
// 	for(int i = k + 1; i <= n && i <= k + arr[k]; i++){
// 		int jumps = minJumps(arr, i, n);
// 		if (jumps != INT_MAX && jumps + 1 < minJump){
// 			minJump = jumps + 1;
// 		}
// 	}

// 	return minJump;
// }


// O(n^2) solution
int minJumpDP(int arr[], int n){
	int dp[n];

	dp[0] = 0;

	for(int i = 1; i < n; i++){
		dp[i] = INT_MAX;
		for(int j = 0; j < i; j++){
			if (dp[j] != INT_MAX && i <= j + arr[j]){
				if (dp[j] + 1 < dp[i]){
					dp[i] = dp[j] + 1;
				}
			}
			
		}
	}

	for(int i = 0; i < n; i++) cout << dp[i] << " ";
	cout << endl;

	return dp[n - 1];
}

// O(n) solution
int minJumps(int arr[], int n){
	int maxReach = arr[0];
	int steps = arr[0];
	int jumps = 1;
	for(int i = 1; i < n; i++){
		if (i == n - 1){
			return jumps;
		}
		maxReach = max(maxReach, i + arr[i]);
		steps--;
		if (steps == 0){
			jumps++;
			steps = maxReach - i;
		}
	}
	return INT_MAX;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		cout << minJumps(arr, n) << endl;
		// cout << minJumpDP(arr, n) << endl;
	}
}