#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sub;

bool uniqueCombinations(int *arr, int n, int key, int sum){
	if (sum == key){
		// for(auto k : sub){
		// 	cout << k << " ";
		// }
		// cout << endl;
		return true;
	}


	for (int i = 0; i < n; i++){

		//assume
		sum += arr[i];
		bool isValid = uniqueCombinations(arr + 1, n - 1, key, sum);
		if (isValid){
			sub.push_back(arr[i]);
			cout << i << endl;
			cout << arr[i] << " ";
			return true;
		} else {
			return false;
		}
	}
	sub.clear();
	return false;
}

int main(){
	int n, key;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> key;

	uniqueCombinations(arr, n, key, 0);
}