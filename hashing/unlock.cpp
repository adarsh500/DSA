#include <bits/stdc++.h>
using namespace std;

int largest = INT_MIN;

void unlock(int arr[], int n, int k, map<int, int> &m){
	int count = 0;
	for(int i = 0; i < n; i++){
		int num = largest - i;
		if (count == k){
			break;
		}

		if (arr[i] == num){
			continue;
		} else {
			int idx = m[largest - i];
			m[num] = i;
			m[arr[i]] = idx;
			swap(arr[i], arr[idx]);
			count++;
		}
	}	
}


int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif 
	int n, k;
	map<int, int> m;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		m[arr[i]] = i;
		largest = max(arr[i], largest);
	}
	unlock(arr, n, k, m);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}