#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	int t;
	cin >> t;
	while(t--){
		int n, count = 0;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n;i++){
			cin >> arr[i];
		}

		for(int i = 0; i < n; i++){
			int lesser = 0, greater = 0;
			for(int j = 0; j < n; j++){
				if (arr[j] <= arr[i]){
					lesser++;
				} else {
					greater++;
				}
			}
			if (lesser > greater){
				count++;
			}
		}
		cout << count << endl;
	}

}