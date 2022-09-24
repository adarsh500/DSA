#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//so you are given a grid, and you have to go from the start till the end. You have to print
	//the total number of paths that can be taken, the cells marked with -1 are obstacles and the 
	/*
	ones marked with 0 are traversable, the rat can move by 1 unit either right or down. But the
	elephant can move max k units right or down.

	ALWAYS REMEMBER: BOTTUP-UP IS THE EASISEST SOLUTION FOR GRID BASED PROBLEMS,
		dp[i][j] = number of ways that this cell can be reached. 
	*/


	int dp[m][n];

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if (i == 0 || j == 0){
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[m - 1][n - 1]


	// you can also use this formula to caluculate(provided that there are no obstacles);
	// (M - 1 + N - 1)! / (M - 1)! * (N - 1)!


	//for the elephant path
	//its almost the same thing 
	/*
	dp[i][j] = ∑(k: 0 to i - 1) dp[k][y] + ∑(k: 0 to y - 1)dp[x][k]

	*/
}