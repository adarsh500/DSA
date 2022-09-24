#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int n, map<int, int> &m){
	vector<int> op;
	for(int i = 0; i < n; i++){
		if (m.count(arr2[i]) && m[arr2[i]] > 0){
			m[arr2[i]]--;
			op.push_back(arr2[i]);
		}

		if (m.count(arr2[i]) == 0){
			m.erase(arr2[i]);
		}
	}

	return op;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	// vector<int> op;
	int n;
	map<int, int> m;
	cin >> n;
	int arr1[n], arr2[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		if (m.count(arr1[i])){
			//present
			m[arr1[i]]++;
		} else {
			m[arr1[i]] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	// for(auto x : m){
	// 	cout << x.first << " ";
	// }
	vector<int> op = intersection(arr1, arr2, n, m);
	sort(op.begin(), op.end());
	cout << "[";
	for(int i = 0; i < op.size() - 1; i++){
		cout << op[i] << ", ";
	}
	cout << op[op.size() -1] << "]" << endl;
}