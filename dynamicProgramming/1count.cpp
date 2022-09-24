#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int left = 0, right = 0, maxLen = 0, zeroCount = 0, begin = 0;
	while(right < n){
		if (arr[right] == 1){
			right++;
		} else {
			zeroCount++;
			right++;
		}

		while(zeroCount > k){
			if (arr[left] == 0){
				zeroCount--;
				left++;
			} else {
				left++;
			}
		}

		if((right - left) > maxLen){
			maxLen = right - left;
			begin = left;
		}
	}

	cout << maxLen << endl;
	for(int i = begin; i <= maxLen; i++){
		arr[i] = 1;
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

}