#include<iostream>
using namespace std;

int main() {
	int m, n, key;
	int arr[100][100];
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> key;


	//staircase search

	// for (int i = 0; i < m;) {
	// 	for (int j = n - 1; j > 0;) {
	// 		int num = arr[i][j];
	// 		if (num < key){
	// 			i++;
	// 			break;
	// 		} else if (num > key){
	// 			j--;
	// 			break;
	// 		} else if (num == key){
	// 			cout << 1;
	// 		} else {
	// 			cout << 0;
	// 		}
	// 	}
	// }

	

	int i = 0, j = n - 1;
	while (i < n) {
		while (j >= 0) {
			int num = arr[i][j];
			if (num < key) {
				i++;
			} else if (num > key) {
				j--;
			} else if (num == key) {
				cout << 1;
				return 0;
			}
		}
	}
cout << 0;
return 0;






	//print the array
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << key;

}