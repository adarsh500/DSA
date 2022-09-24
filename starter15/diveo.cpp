#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while(t--){
		int n, a, b;
		cin >> n >> a >> b;
		int evenCount = 0, oddCount = 0;
		while(n % 2 == 0 && n > 0){
			n = n / 2;
			evenCount++;
		}
		for(int i = 3; i <= n; i++){
			if (n % i == 0){
				while(n % i == 0){
					n = n / i;
					oddCount++;
				}
			}
		}

		//this means that after division, n has become an odd number;
		//so we divide n by n and we incurease oddCount
		if (n != 1){
			oddCount++;
		}

		int points = 0;

		if (a >= 0 && b >= 0){
			points = evenCount * a + oddCount * b;
		} else if (a <= 0 && b <= 0) {
			if (evenCount){
				points = a;
			} else {
				points = b;
			}
		} else if (a >= 0 && b <= 0){
			if (evenCount){
				points = evenCount * a;
			} else {
				points = b;
			}
		} else if (a <= 0 && b >= 0){
			if (evenCount){
				points = a + oddCount * b;
			} else {
				points = oddCount * b;
			}
		}

		cout << points << endl;
	}	
}