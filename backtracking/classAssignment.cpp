// This is the original solution however this gives us tle
// this is only for your understanding, the real solution is at the bottom

// #include <iostream>
// #include <string>
// #include <set>
// using namespace std;

// void perm(int n, int i, string output, set<string> &s){
// 	if (i == n){
// 		// cout << output << endl;
// 		string temp(output);
// 		s.insert(temp);
// 		return;
// 	}

// 	perm(n, i + 1, "a" + output, s);

// 	if (output[i - 1] != 'b'){
// 		perm(n, i + 1, "b" + output, s);
// 	}
// 	return;
// }

// int main(){
// 	int t;
// 	cin >> t;
// 	int i = 1;
// 	while (t--){
// 		int n, count = 0;
// 		cin >> n;
// 		set<string> s;

// 		perm(n, 0, "", s);

// 		// cout << s.size() << endl;
// 		cout << "#" << i << " : " << s.size() << endl;
// 		i++;
// 	}
// }


//solution

#include<iostream>
using namespace std;

long long int countWays(int n) {

	long long int dp[n + 1] = {0};
	dp[1] = 2;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		cout << "#" << i << " : " << countWays(n) << endl;
	}
	return 0;
}