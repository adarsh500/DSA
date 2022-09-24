#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWith0Sum(int arr[], int n){
	unordered_map<int, int> m;
	int pre = 0, len = 0;
	for (int i = 0; i < n; i++){
	 	pre += arr[i];

	 	if (pre == 0){
	 		len = i + 1;
	 	}

	 	if (m.find(pre) != m.end()){
	 		len = max(len, i - m[pre]);
	 	} else {
	 		m[pre] = i;
	 	}
	}
	return len;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << longestSubarrayWith0Sum(arr, n) << endl;


}