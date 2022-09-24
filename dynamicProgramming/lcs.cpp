#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s1, string s2, int i, int j){
	if (i == s1.length() or j == s2.length()){
		return 0;
	}

	if (s1[i] == s2[j]){
		return 1 + lcs(s1, s2, i + 1, j + 1);
	}

	int option1 = lcs(s1, s2, i + 1, j);
	int option2 = lcs(s1, s2, i, j + 1);

	return max(option2, option1);
}

//with memoisation
int lcs(string s1, string s2, int i, int j, vector <vector<int> > &dp){
	if (i == s1.length() or j == s2.length()){
		return 0;
	}

	if (dp[i][j] != -1){
		return dp[i][j];
	}

	if (s1[i] == s2[j]){
		return dp[i][j] =  1 + lcs(s1, s2, i + 1, j + 1, dp);
	}

	int option1 = lcs(s1, s2, i + 1, j, dp);
	int option2 = lcs(s1, s2, i, j + 1, dp);

	return dp[i][j] = max(option2, option1);
}


//bottom up approach
int lcs(string s1, string s2){
	//the difference between this and top down is that here i and j denotes the 
	//number of charecters that we are consdiering from s1 ans s2. i, j = 0 means
	//we are not considering any charecters from both, and s1, s2 = 1 means that 
	//we are considering the first charecters from both
	int n1 = s1.length();
	int n2 = s2.length();

	vector< vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for(int i = 1; i <= n1; i++){

		for(int j = 1; j <= n2; j++){
			
			//note here we are using 1 based indexing so we subtract -1
			if (s1[i - 1] == s2[j - 1]){ 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				int option1 = dp[i][j - 1];
				int option2 = dp[i - 1][j];
				dp[i][j] = max(option1, option2);
			}
		}
	}

	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	/*
	for example input is abedg and abcd
	dp will look like
	      a b c d
	   	0 0 0 0 0 
	   a0 1 1 1 1 
	   b0 1 2 2 2 
	   e0 1 2 2 2 
	   d0 1 2 2 3 
	   g0 1 2 2 3 	
	*/

	//to print the lcs
	vector<char> ans;
	int i = n1, j = n2;
	while(i != 0 and j != 0){
		if (dp[i][j] == dp[i][j - 1]){
			j--;
		} else if (dp[i][j] == dp[i - 1][j]){
			i--;
		} else {
			ans.push_back(s1[i - 1]);
			//or ans.push_back(s2[i - 1])
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	for(char x : ans){
		cout << x;
	}
	cout << endl;

	return dp[n1][n2];

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s1, s2;
	cin >> s1 >> s2;

	int n1 = s1.length();
	int n2 = s2.length();

	vector <vector<int> > dp(n1, vector<int>(n2, -1));
	//we are initializing the dp vector of n1 rows where each row will have n2 vectors 
	//containing the value -1;

	cout << lcs(s1, s2, 0, 0) << endl;


	cout << lcs(s1, s2, 0, 0, dp) << endl;
	// for(int i = 0; i < n1; i++){
	// 	for(int j = 0; j < n2; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << lcs(s1, s2) << endl;
}