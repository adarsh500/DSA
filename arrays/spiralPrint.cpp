#include<iostream>
using namespace std;

int main() {
	int row, col;
	cin >> row >> col;
	int arr[row][col];


	//taking input for the array
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}

	int startRow = 0, endRow = row - 1;
	int startCol = 0, endCol = col - 1;



	//Spiral print clockwise

	// while (startRow <= endRow and startCol <= endCol) {

	// 	for (int i = startCol; i <= endCol; i++) {
	// 		cout << arr[startRow][i] << ", ";
	// 	}
	// 	startRow++;

	// 	for (int i = startRow; i <= endRow; i++) {
	// 		cout << arr[i][endCol] << ", ";
	// 	}
	// 	endCol--;

	// 	if (startRow < endRow) {
	// 		for (int i = endCol; i >= startCol; i--) {
	// 			cout << arr[endRow][i] << ", ";
	// 		}
	// 		endRow--;
	// 	}


	// 	if (startCol < endCol) {
	// 		for (int i = endRow; i >= startRow; i--) {
	// 			cout << arr[i][startCol] << ", ";
	// 		}
	// 		startCol++;
	// 	}
	// }



	//Spiral print anticlockwise

	while (startRow <= endRow and startCol <= endCol) {

		for (int i = startRow; i <= endRow; i++) {
			cout << arr[i][startCol] << ", ";
		}
		startCol++;

		for (int i = startCol; i <= endCol; i++) {
			cout << arr[endRow][i] << ", ";
		}
		endRow--;

		//if (startCol < endCol) {
			for (int i = endRow; i >= startRow; i--) {
				cout << arr[i][endCol] << ", ";
			}
			endCol--;
		//}


		//if (startRow < endRow) {
			for (int i = endCol; i >= startCol; i--) {
				cout << arr[startRow][i] << ", ";
			}
			startRow++;
		//}
	}
	cout << "END";
}
