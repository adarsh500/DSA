#include<iostream>
#include<algorithm>
using namespace std;

void rotateWithoutStl(int arr[][1000],int n) {

	//reverse the row

	for (int i = 0; i < n; i++) {
		int startCol = 0, endCol = n - 1;
		while (startCol < endCol) {
			swap(arr[i][startCol], arr[i][endCol]);
			startCol++;
			endCol--;
		}
	}

	//transpose the 2D array

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {  // does the transpose only once for the upper triangular matrix
				swap(arr[i][j], arr[j][i]);
			}
		}
	}

}

// void rotateWithStl(int arr[][1000],int n) {

// 	//reverse the row

// 	for (int i = 0; i < n; i++) {
// 		reverse(arr[i], arr[i] + n);
// 	}

// 	//transpose the 2D array

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (i < j) {  // does the transpose only once for the upper triangular matrix
// 				swap(arr[i][j], arr[j][i]);
// 			}
// 		}
// 	}
// }

int main() {
	int n;
	cin >> n;
	int arr[1000][1000];


	//taking input for the array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//rotate without stl
	rotateWithoutStl(arr, n);

	//rotate with stl
	// rotateWithStl(arr, n);

	//print the array 
	for(int i = 0; i< n; i++){
		for (int j = 0; j < n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}