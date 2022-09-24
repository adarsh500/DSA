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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, setBits = 0;
		cin >> a >> b;

		for (int i = a; i <= b; i++) {
			setBits += countSetBits(i);
		}

		cout << setBits << endl;
	}
	return 0;
}