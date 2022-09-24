#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int arr[n][m];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	//suffix sum matrix

		//horizontal addition
		for (int i = n - 1; i >=0; i--){
			for (int j = m - 2; j >= 0; j--){
				arr[i][j] += arr[i][j + 1];
			}
		}

		//vertical addition
		for (int i = n - 1; i >=0; i--){
			for (int j = m - 2; j >= 0; j--){
				arr[j][i] += arr[j + 1][i];
			}
		}


	//traversing the array to find the max sum submatrix
	int max = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[i][j] > max){
				max = arr[i][j];
			}
		}
	}


	cout << max;
	// //print the matrix
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < m; j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

}