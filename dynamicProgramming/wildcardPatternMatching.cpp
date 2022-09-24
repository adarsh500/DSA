#include <bits/stdc++.h>
using namespace std;

bool patternMatch(string text, string pattern, int n, int m, vector< vector<bool>> &dp){
	//n is text length, m is pattern length
	if (m == 0){
		return n == 0;
	}

	dp[0][0] = true;
	//matching passes if both the lengths of text and pattern is 0
	for(int i = 1; i <= m; i++){
		if (pattern[i - 1] == '*'){
			dp[0][i] = dp[0][i - 1];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if (pattern[j - 1] == '*'){
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			} else if (pattern[j - 1] == '?' || pattern[j - 1] == text[i - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = false;
			}
		}
	}

	return dp[n][m];
	
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	string text, pattern;
	cin >> text >> pattern;
	vector<vector<bool> > dp(text.length() + 1, vector<bool>(pattern.length() + 1, false));

	cout << patternMatch(text, pattern, text.length(), pattern.length(), dp) << endl;
}