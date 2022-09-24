#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, key;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> key;

	//2 Pointer method
	// int i = 0, j = n - 1;
	// while (i != j){
	// 	int sum = arr[i] + arr[j];
	// 	if (sum < key){
	// 		i++;
	// 	} else if (sum > key){
	// 		j--;
	// 	} else {
	// 		cout << arr[i] << " and " << arr[j] << endl;
	// 		i++;
	// 		j--;
	// 	}
	//}
	sort(arr, arr + n);

	// brute force method - N^2 complexity
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++){
	// 		if (i != j && (key == arr[i] + arr[j])){
	// 			cout << arr[i] << " and " << arr[j] << endl;
	// 			arr[i] = -999, arr[j] = -999;
	// 		}
	// 	}
	// }

	int left = 0, right = n - 1;
	while(left < right){
		int sum = arr[left] + arr[right];
		if (sum < key){
			left++;
		} else if (sum > key){
			right--;
		} else {
			cout << arr[left] << " and " << arr[right] << endl;
			left++;
			right--;
		}
	}


	return 0;
}