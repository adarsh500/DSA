#include <bits/stdc++.h>
using namespace std;


int knapsack(int n, int capacity, int weight[], int value[]){
	int dp[1001] = {0};

	for(int i = 1; i <= capacity; i++){
		for(int j = 0; j < n; j++){
			if (weight[j] <= i){
				dp[i] = max(dp[i], value[j] + dp[i - weight[j]]);				
			}
		}
	}

	// for(int i = 0; i <= capacity; i++){
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;

	return dp[capacity];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, capacity;
	cin >> n >> capacity;

	int weight[n], value[n];
	for(int i = 0; i < n; i++){
		cin >> weight[i];
	}
	for(int i = 0; i < n; i++){
		cin >> value[i];
	}

	cout << knapsack(n, capacity, weight, value) << endl;
}