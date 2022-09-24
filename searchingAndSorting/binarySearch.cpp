#include <iostream>
using namespace std;

int main(){
	long long int n, m;
	cin >> n;

	long long int arr[n];
	for (long long int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cin >> m;

	long long int start = 0, end = n - 1, mid;
	while (start <= end){
		mid = (start + end) / 2;
		if (arr[mid] == m){
			cout << mid << endl;
			return 0;
		} else if (arr[mid] < m){
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	cout << -1 << endl;
	return 0;
}