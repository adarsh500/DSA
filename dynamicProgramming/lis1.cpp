//lis stands for Longest increasing subsequence
#include <iostream>
using namespace std;
	

int lis1(int arr[], int n){
	int dp[100000] = {0};
	dp[0] = 1;
	
	// int j = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if (arr[j] < arr[i]){
				dp[i] = max(dp[j], dp[i]);			
			}
		}
		dp[i]++;
	}

	for (int i = 0; i < n; i++)	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n - 1];
}

int lis2(int arr[], int n){
	int dp[100000] = {0};
	//i represents the element at which subsequence of length i ends. 
	//this is exactly the oppposite of lis1. watch lis3 video again for clarity
	//if there are multiple elements then always consider the smaller one
	dp[0] = INT_MIN;
	for(int i = 1; i <= n; i++){
		dp[i] = INT_MAX;
	}

	for(int i = 0; i < n; i++){
		for(int length = 0; length <  n; length++){
			if (dp[length] < arr[i] and arr[i] < dp[length + 1]){
				dp[length + 1] = arr[i];
			}
		}
	}

	int lis = 0;
	for(int i = 1; i < n; i++){
		if (dp[i] != INT_MAX){
			lis = i;
		}
	}
	cout << lis << endl;
	return lis;
}

int lis3(int arr[], int n){
	int dp[100000] = {0};
	dp[0] = INT_MIN;
	for(int i = 1; i <= n; i++){
		dp[i] = INT_MAX;
	}

	//since we know that the dp array is strictly increasing, we can use binary search
	//to make it more effecient. We can use the upper_bound() function to find the index
	//length + 1 (observe lis2, we replace dp[length + 1] with arr[i] so we are using
	//binary search to find the index of length + 1);

	for(int i = 0; i < n; i++){
		int length = upper_bound(dp, dp + n + 1, arr[i]) - dp;
		//we add addition -dp to subtract it from the starting address so we get the index;
		if (dp[length - 1] < arr[i] and arr[i] < dp[length]){
			//we check if the prev element in dp array if smaller or not so that we can
			//be sure that dp array is strictly increasing
			dp[length] = arr[i];
		}
	}
	int lis = 0;
	for(int i = 1; i < n; i++){
		if (dp[i] != INT_MAX){
			lis = i;
		}
	}
	return lis;
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

	//NOTE: we need to find a subsequence not a subarray, that means that the element can be taken
	//from any array index provided that it is in order

	// cout << lis1(arr, n) << endl;
	cout << lis2(arr, n) << endl;
	cout << lis3(arr, n) << endl;
}