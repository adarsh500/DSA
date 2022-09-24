#include <iostream>
using namespace std;

int numberOfPairs(int n){
	int dp[n + 1];

	for(int i = 0; i <= n; i++){
		if (i <= 2){
			dp[i] = i;
		} else {
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
		}
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

	cout << numberOfPairs(n) << endl;
}