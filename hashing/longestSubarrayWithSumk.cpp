#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k){
	unordered_map<int, int> m;
	int pre = 0, len = 0;
	for (int i = 0; i < n; i++){
	 	pre += arr[i];

	 	if (pre == k){
	 		len = i + 1;
	 	}

	 	if (m.find(pre - k) != m.end()){
	 		len = max(len, i - m[pre - k]);
	 	} else  {
	 		//store the first occurence
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
	int n, k;
	cin >> n >> k ;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << longestSubarrayWithSumK(arr, n, k) << endl;


}