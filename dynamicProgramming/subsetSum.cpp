#include <bits/stdc++.h>
using namespace std;

bool subsetIsPresent(int arr[], int n, int sum){
	if (sum == 0){
		return true;
	} 
	if (n == 0 && sum != 0){
		return false;
	}

	if (arr[n] <= sum){
		return subsetIsPresent(arr, n - 1, sum - arr[n]) || subsetIsPresent(arr, n - 1, sum);
	} 
	return subsetIsPresent(arr, n - 1, sum);

	// return false;
}

bool subsetIsPresentBU(int arr[], int n, int sum){
	bool dp[n + 1][sum + 1];

	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
		//i represents that we are considering i elements of the array and j represents that
		//the target sum is 0
	}

	for(int j = 0; j <= sum; j++){
		dp[0][j] = false;
		//i represents that we are considering 0 elements of the array and j represents that
		//the target sum is j
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if (j >= arr[i - 1]){
				dp[i][j] = dp[i - 1][j - arr[i - 1]] ||  dp[i - 1][j];
				//dp[i][j] = include || exclude;
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][sum];
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	if (subsetIsPresent(arr, n - 1, sum)){
		cout << "Yes";
	} else {
		cout << "No";
	}



	cout << "\n";
}