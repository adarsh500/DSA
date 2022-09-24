#include <iostream>
using namespace std;

//--------------------------METHOD 1----------------------------
// int lastOcc(int * arr, int n, int key){
// 	if (n == 0){
// 		return -1;
// 	}
// 	//recursion case
// 	int i = lastOcc(arr + 1, n - 1, key);
// 	if (i == -1){
// 		if (arr[0] == key){
// 			return 0;
// 		} else {
// 			return -1;
// 		}
// 	}
// 	return i + 1;
// }

//--------------------------METHOD 2----------------------------
int lastOcc(int * arr, int n, int i, int key){
	if (i == n){
		return -1;
	}
	int result = lastOcc(arr, n, i + 1, key);
	if (arr[i] == key and result == -1){
		return i;
	} 
	return result;
}

int main(){
	int n, key;
	cin >> n;

	int arr[999];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> key;

	// cout << lastOcc(arr, n, key) << endl;
	cout << lastOcc(arr, n, 0, key) << endl;

}