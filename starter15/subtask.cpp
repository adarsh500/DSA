#include <iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while(t--){
		bool test = true;
		int n, m, k, count = 0, points = 0;
		cin >> n >> m >> k;
		int arr[100];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i] == 1){
				count++;
			}
		}

		for(int i = 0; i < m; i++){
			if (arr[i] == 0){
				test = false;
				break;
			} 
		}

		if (test == false){
			points = 0;
		} else if (count == n){
			points = 100;
		} else {
			points = k;	
		}
		cout << points << endl;
	}	
}