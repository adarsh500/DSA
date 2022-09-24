//-----------------------------My solution--------------------------
// most test cases passing


// #include <iostream>
// #include <cmath>
// using namespace std;

// #define ull unsigned long long int

// int toBinary(int n){
// 	ull res = 0, p = 1;
// 	while (n > 0){
// 		int rem = n % 10;
// 		res = rem * p;
// 		p *= 10;
// 		n = n / 10;
// 	}
// 	return res;
// }

// int main(){
// 	ull n, p, ans;
// 	cin >> n >> p;

// 	ull binaryPower = toBinary(p);

// 	ull exp = 1;
// 	while(binaryPower > 0){
// 		ull rem = binaryPower % 10;
// 		ull power = rem * exp;
// 		ans *= pow(n, power);
// 		binaryPower /= 10;
// 		exp *= 2;
// 	}

// 	cout << ans << endl;
// 	return 0;
// }

//-----------------------------CB solution------------------------
// all test cases passing

#include <iostream>
using namespace std;
#define ull unsigned long long int


int power(int n, int p) {
	int res = 1;
	while (p > 0) {
		int lastBit = p & 1;
		if (lastBit) {
			res = res * n;
		}
		n *= n;
		p = p >> 1;
	}
	return res;
}

int main() {
	ull n, p, ans;
	cin >> n >> p;
	cout << power(n, p) << endl;
}