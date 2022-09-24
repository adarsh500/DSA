/*
This is a standard Dp / greedy problem. It can be solved using both. However, the greedy approach
might not work for every currency. It works for few like indian Currency.
Eg:- 
coins = [1, 7, 10];
and amount = 15; Greedy won't work for this
*/


//the time complexity for both will be O(TN) where t is the number of coins.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(int n, vector<int> coins, int dp[]){
	//this is the top down approach
	if (n == 0){
		return 0;
	}

	if (dp[n] != 0){
		return dp[n];
	}

	int ans = INT_MAX;
	for(int i = 0; i < coins.size(); i++){
		if (n - coins[i] >= 0){
			// mini = min(mini, minCoins(n - coins[i], coins, count++));
			int subprob = minCoins(n - coins[i], coins, dp);	
			ans = min(ans, subprob + 1);
		}
	}
	dp[n] = ans;

	return dp[n];
}

int mincoins(int n, vector<int> coins){
	int dp[10000] = {0};


	for(int i = 1; i <= n; i++){
		dp[i] = INT_MAX;
		for(int j = 0; j < coins.size(); j++){
			if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
				int subprob = dp[i - coins[j]];
				dp[i] = min(dp[i], subprob + 1);
			}
		}
	}

	if (dp[n] == INT_MAX){
		return 0;
	}
	return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int> coins = {1, 7, 10};
	int dp[10000] = {0};
	int n;
	cin >> n;

	// cout << minCoins(n, coins, dp) << endl;
	cout << mincoins(n, coins) << endl;
}