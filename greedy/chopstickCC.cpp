#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, d, count = 0;
	cin >> n >> d;

	int arr[n];
	for(int i = 0;i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for(int i = 1;i < n; i++){

		if (arr[i] - arr[i - 1] <= d && arr[i] > 0 && arr[i - 1] > 0){
			count++;
			arr[i] = -1;
			arr[i -1] = -1;

		}
	}

	cout << count << endl; 


}