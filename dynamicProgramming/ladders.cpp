#include <iostream>
using namespace std;


//Space is O(N) and time is O(NK)
//same for bottom up
int numberOfWays(int n, int k, int dp[]){
	if (n == 0){
		return 1;
	}

	if (dp[n] != 0){
		return dp[n];
	}

	int ans = 0;
	for(int i = 1; i <= k; i++){
		if (n - i >= 0){
			ans += numberOfWays(n - i, k, dp);			
		}
	}

	return dp[n] = ans;
}


int numberOfWaysBU(int n, int k){
	int dp[10000] = {0};

	dp[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if (i - j >= 0){
				dp[i] += dp[i - j];
			}
		}
	}

	//to see the bottom up array
	for(int i = 0; i <= n ; i++){
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n];
}

int optimizedNumberOfWays(int n, int k){
	int start = 0, sumTillNow = 1, count = 1;
	int dp[10000] = {0};
	dp[0] = 1;


	for(int i = 1; i <= n; i++){
		dp[i]= sumTillNow;			
		if (count >= k){
			sumTillNow -= dp[start];
			start++;
		}
		sumTillNow += dp[i];
		count++;
	}

	for(int i = 0; i <= n ; i++){
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n];
}

int anotherOptimizedImplementation(int n, int k){
	int dp[10000] = {0};

	dp[0] = dp[1] = 1;

	for(int i = 2; i <= k; i++){
		dp[i] = (2 * dp[i - 1]);
	}

	for(int i = k + 1; i <= n; i++){
		dp[i] = (2 * dp[i - 1]) - dp[i - k - 1];
	}

	for(int i = 0; i <= n ; i++){
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;

	int dp[10000] = {0};

	cout << numberOfWays(n, k, dp) << endl;
	cout << "Bottom up ways is " << endl;
	cout << numberOfWaysBU(n, k) << endl;
	cout << optimizedNumberOfWays(n, k) << endl;
	cout << anotherOptimizedImplementation(n, k) << endl;
}