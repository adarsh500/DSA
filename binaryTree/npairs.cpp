#include <iostream>
#include <cmath>
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
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				if ((j - 1) == abs(arr[j] - arr[i])){
					count++;
				}
			}
		}

		cout << count << endl;
	}

}