#include <iostream>
using namespace std;


//TOP DOWN with memoization
int maxProfit(int arr[], int year, int left, int right, int dp[][1000]){
	if (left > right){
		return 0;
	}

	if (dp[left][right] != 0){
		return dp[left][right];
	}

	int consideringLeft = arr[left] * year + maxProfit(arr, year + 1, left + 1, right, dp);
	int consideringRight = arr[right] * year + maxProfit(arr, year + 1, left, right - 1, dp);

	return dp[left][right] = max(consideringRight, consideringLeft);
}
  

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int dp[1000][1000] = {0};
	cout << maxProfit(arr, 1, 0, n - 1, dp) << endl;
}