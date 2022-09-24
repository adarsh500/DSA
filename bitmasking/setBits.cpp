#include <iostream>
using namespace std;

int countSetBits(int n) {
	int res = 0;
	if (n == 1){
		return 1;
	} else {
		while (n > 0) {
		n = (n & (n - 1));
		res++;
		}
		return res;
	}
}

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++){
		cout << countSetBits(arr[i]) << endl;
	}
	return 0;
}
