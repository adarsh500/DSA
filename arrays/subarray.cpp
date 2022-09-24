#include <iostream>
using namespace std;

void subarray(int arr[], int n, int k){
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			for (int l = i; l <= k; l++){
				cout << arr[j]<< " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	subarray(arr, n, k);
}


// #include<bits/stdc++.h>
// using namespace std;
// int main() {

// 	long n, k;
//     cin >> n >> k;
    
//     int arr[100000];
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
    
//     int keys[100000][k], row = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//         	for (int l = j + 1; l < n; l++){
//         		int col = 0
//         		for (; row < 100000; row++){
//         			keys[row][]
//         		}
//                 //cout << arr[i] << arr[j] << arr[l] << " ";
//                 //keys[]
// 			}    
//             //cout << endl;
// 		}
//     }
// }