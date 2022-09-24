#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n, x, bounceCount = 0, sum = 0;
	cin >> n >> x;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++){
		sum += arr[i];
		if (sum <= x){
			bounceCount++;
		}
	}

	cout << (bounceCount + 1) << endl;
}