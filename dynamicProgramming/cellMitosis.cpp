#include <iostream>
using namespace std;

int leastOperationsToReachN(int n, int x, int y, int z){
	int dp[n + 1];

	dp[1] = dp[0] = 0;
	for(int i = 2; i <= n; i++){
		if (i&1){
			//odd
			//this means we can either come previous index or the next index.if i is odd, 
			//then next index is even and we can reach the next index by doubling a value
			dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
		} else {
			//even
			//this means we can either come from the previous index or by doubling the index
			dp[i] = min(dp[i - 1] + y, dp[i / 2] + x);			
		}
	}

	return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, x, y, z;
	cin >> n >> x >> y >> z;


	cout << leastOperationsToReachN(n, x, y, z) << endl;
}