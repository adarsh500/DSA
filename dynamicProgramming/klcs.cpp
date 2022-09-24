#include <iostream>
using namespace std;

int klcs(int a, int b, int c, int arr1[],int arr2[]){
	int dp[a + 1][b + 1][c + 1];

	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			for(int k = 0; k <= c; k++){
				if (i == 0 || j == 0 || k == 0){
					dp[i][j][k] = 0;
				} else if (arr1[i] == arr2[j]){
					int option1 = 1 + dp[i - 1][j - 1][k];
					int option2 = dp[i - 1][j][k];
					int option3 = dp[i][j - 1][k];

					dp[i][j][k] = max(option1, max(option2, option3));
				} else {
					int option1 = dp[i - 1][j - 1][k - 1] + 1;
					int option2 = dp[i - 1][j][k];
					int option3 = dp[i][j - 1][k];

					dp[i][j][k] = max(option1, max(option2, option3));
				}
			}
		}
	}

	// for(int i = 0; i <= a; i++){
	// 	for(int j = 0; j <= b; j++){
	// 		for(int k = 0; k <= c; k++){
	// 			cout << dp[i][j][k] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// 	cout << endl;
	// }

	return dp[a][b][c];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	int arr1[n], arr2[m];
	for(int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < m; i++){
		cin >> arr2[i];
	}


	cout << klcs(n, m, k, arr1, arr2) << endl;
}