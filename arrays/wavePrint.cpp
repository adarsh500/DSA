#include<iostream>
using namespace std;

int main(){
	int rows, cols;
	cin >> rows >> cols;
	int arr[rows][cols];


	//taking input for the array
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cin >> arr[i][j];
		}
	}

	//wave print
	for (int j = 0; j < cols; j++){
		if (j % 2 == 0){
			//top-down
			for (int i = 0; i < rows; i++){
				cout << arr[i][j] << ", ";
			}
		} else {
			//bottom-up
			for(int i = rows - 1; i >= 0; i--){
				cout << arr[i][j] << ", ";
			}
		}
	}
	cout << "END";



	// //printing the array
	// for (int i = 0; i < rows; i++){
	// 	for (int j = 0; j < cols; j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
}
