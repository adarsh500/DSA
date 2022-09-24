#include <iostream>
using namespace std;

bool checkSubset(int arr[], int n, int sum, int i, bool included = false){
	if (i == n){
		return (sum == 0 && included);
	}
	bool exc = checkSubset(arr, n, sum, i + 1, included);
	bool inc = checkSubset(arr, n, sum + arr[i], i + 1, true);
	return inc || exc;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}

		if (checkSubset(arr, n, 0, 0)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}