#include <iostream>
#include <vector>
#include <string>
using namespace std;

string lcs(string s1, string s2, int i, int j){
	string ans = "";
	if (i == s1.length() or j == s2.length()){
		return "";
	}

	if (s1[i] == s2[j]){
		return s1[i] + lcs(s1, s2, i + 1, j + 1);
	}

	string option1 = lcs(s1, s2, i + 1, j);
	string option2 = lcs(s1, s2, i, j + 1);

	if (option2.length() > option1.length()){
		return option2;
	}

	return option1;
}

//dp  with memoisation
string lcs(string s1, string s2, int i, int j, vector <vector<string> > &dp){
	if (i == s1.length() or j == s2.length()){
		return "";
	}

	string ans = "";

	if (dp[i][j] != ""){
		return dp[i][j];
	}

	if (s1[i] == s2[j]){
		return dp[i][j] =  s1[i] + lcs(s1, s2, i + 1, j + 1, dp);
	}

	string option1 = lcs(s1, s2, i + 1, j, dp);
	string option2 = lcs(s1, s2, i, j + 1, dp);

	if (option2.length() > option1.length()){
		return dp[i][j] = option2;
	}

	return dp[i][j] = option1;
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

	vector <vector<string> > dp(n1, vector<string>(n2, ""));
	//we are initializing the dp vector of n1 rows where each row will have n2 vectors 
	//containing the value -1;

	// cout << lcs(s1, s2, 0, 0) << endl;


	cout << lcs(s1, s2, 0, 0, dp) << endl;
}