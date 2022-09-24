#include <iostream>
#include <climits>
using namespace std;

int minStepsTD(int n, int dp[]){

	//O(N)
	if (n == 1){
		return 0;
	}

	if (dp[n] != 0){
		return dp[n];
	}
	int x = minStepsTD(n - 1, dp) + 1, y = INT_MAX, z = INT_MAX;
	if (n % 2 == 0){
		y = minStepsTD(n / 2, dp) + 1;		
	}

	if (n % 3 == 0){
		z = minStepsTD(n / 3, dp) + 1;
	}

	int ans = min(x, min(y, z));

	return dp[n] = ans;	
}

int minStepsBU(int n){
	int dp[n];
	dp[1] = 0, dp[0] = 0;
	int x;
	for(int i = 2; i <= n; i++){
		int y = INT_MAX, z = INT_MAX;
		if (i % 2 == 0){
			// y = minStepsBU(i / 2);
			y = dp[i / 2];
		}
		if (i % 3 == 0){
			z = dp[i / 3];
		} 
		x = dp[i - 1];


		dp[i] = min(x, min(y, z)) + 1;
		// cout << dp[i] << endl;
 	}
	return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;

	int dp[100000] = {0};
	cout << minStepsTD(n, dp) << endl;

	// cout << minStepsBU(n) << endl;
}