/*
Time Complexity, space complexity: O(N)
space is O(N) because, at any given point of time there is maximum on n fibo calls
in the call stack
*/


//TOP DOWN DP
#include <iostream>
using namespace std;

int fibo(int n, int dp[]){
	if (n == 0 || n == 1){
		return n;
	}

	if (dp[n] != 0){
		return dp[n];
	}

	int ans = fibo(n - 1, dp) + fibo(n - 2, dp);
	return dp[n] = ans;
}

//BOTTOM UP DP
//space and time same as above
int fibo(int n){
	int dp[100000] = {0};

	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

//BOTTOM UP WITH OPTIMIZATION
//here the space complexity is constant
int fiboOptimized(int n){
	int a = 0, b = 1, c;
	for(int i = 2; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

//you can further reduce the time complexity using matrix exponentation
//do research

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	int dp[1000000] = {0};

	// cout << fibo(n, dp) << endl;
	cout << fiboOptimized(n) << endl;
}