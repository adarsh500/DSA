#include <iostream>
using namespace std;

int maxProfit(int prices[], int n){
	if (n == 0){
		return 0;
	}

	int price = INT_MIN;
	for(int i = 0; i < n; i++){
		int cut = i + 1;
		price = max(prices[i] + maxProfit(prices, n - cut), price);
	}

	return price;
}

int maxProfitDp(int prices[], int n){
	int dp[n + 1];
	dp[0] = 0;

	for(int len = 1; len <= n; len++){
		int ans = INT_MIN;
		for(int i = 0; i < len; i++){
			int cut = i + 1;
			int currentAns = prices[i] + dp[len - cut];
			ans = max(currentAns, ans);
		}
		dp[len] = ans;
	}

	return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int n = 8;

	cout << maxProfit(prices, n) << endl;
	cout << maxProfitDp(prices, n) << endl;

}