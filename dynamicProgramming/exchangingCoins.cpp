#include <iostream>
#define int long long
#define MAX 10000000
using namespace std;

int dp[MAX] = {0};

int exchange(int n){
	if(n == 1){
		return 1;
	} else if ( n == 0){
		return 0;
	} 

	if(n < MAX && dp[n] != 0){
		//NOTE THIS above statement works but not the lower statement
	// if (dp[n]!= 0 && n < MAX){
		return dp[n];
	}

	if (n > MAX){
		return max(exchange(n/2) + exchange(n/3) + exchange(n/4), n);
	}
	return dp[n] = max(exchange(n/2) + exchange(n/3) + exchange(n/4), n);
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;

	cout << exchange(n) << endl;
}