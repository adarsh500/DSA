//----------------------------My Solution-------------------------

// #include <iostream>
// #include <cmath>
// using namespace std;

// #define ull unsigned long long int

// int convertToBinary(ull n) {
// 	ull res = 0, p = 1;
// 	while (n > 0) {
// 		int rem = n % 2;
// 		res += (rem * p);
// 		n /= 2;
// 		p *= 10;
// 	}
// 	return res;
// }

// int main() {
// 	ull n, maxi;
// 	cin >> n;

// 	ull arr[100000];
// 	for (int i = 0; i < n; i++) {
// 		ull num;
// 		cin >> num;
// 		arr[i] = convertToBinary(num);
// 		maxi = max(maxi, arr[i]);
// 	}

// 	ull output[64] = {0}, pos = 63;

// 	while (maxi > 0) {
// 		ull count = 0;
// 		for (int i = 0; i < n; i++) {
// 			int rem = arr[i] % 10;
// 			if (rem == 1) {
// 				count++;
// 			}
// 			arr[i] /= 10;
// 		}
// 		output[pos] = count;
// 		pos--;
// 		maxi /= 10;
// 	}



// 	ull oddNumber, p = 1;
// 	for (int i = 63; i >= 0; i--) {
// 		output[i] %= 3;
// 		oddNumber += p * output[i];
// 		p *= 2;
// 	}
// 	cout << oddNumber << endl;
// }


//---------------------CB SOLUTION-------------------------
//Much more optimised, shorter and neater


#include <iostream>
using namespace std;

int main(){
	int output[64] = {0};

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		int num;
		cin >> num;

		int pos = 0;
		while (num > 0){
			int lastBit = num&1;
			output[pos] += lastBit;
			pos++;
			num = num >> 1;
		}
	}

	int p = 1, ans = 0;
	for (int i = 0 ; i < 64; i++){
		output[i] %= 3;
		ans += (output[i] * p);
		p *= 2;
	}

	cout << ans << endl;
	return 0;
}