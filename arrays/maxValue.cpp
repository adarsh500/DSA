#include<iostream>
#include<climits>
using namespace std;

int main() {
	int n;
	int i = 0;
	cin >> n;
	int arr[n];
	while(i < n){
		cin >> arr[i];
		i++;
	}
	int max = -INT_MAX;
	for (int i = 0; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	cout << max;
}