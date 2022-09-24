#include <bits/stdc++.h>
using namespace std;
	
bool exists(int arr[], int n, int num, unordered_map<int, int> &m){
	if (m.count(num)){
		return true;
	}
	return false;
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif 
	int t;
	cin >> t;
	while(t--){
		unordered_map<int, int> m;
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			m[arr[i]] = i;
		}
		int q;
		cin >> q;
		while(q--){
			int num;
			cin >> num;
			if (exists(arr, n, num, m)){
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	

}