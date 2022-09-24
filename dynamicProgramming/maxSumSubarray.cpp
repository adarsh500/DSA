#include <iostream>
using namespace std;


//TOP DOWN with memoization
int maxSum(int arr[], int n){
	int dp[10000] = {0};

	dp[0] = (arr[0] > 0) ? arr[0] : 0;
	int maxSum = dp[0];

	for(int i = 1; i < n; i++){
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] < 0){
			dp[i] = 0;
		}

		maxSum = max(maxSum, dp[i]);
	}
	return maxSum;
}
  
//space optimized 
//use kadane also, where instead of storing the whole array, just store the maximum of i - 1 th element

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

	cout << maxSum(arr, n) << endl;
}