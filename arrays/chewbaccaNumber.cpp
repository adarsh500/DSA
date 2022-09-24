// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

// Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.


// Input Format
// The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.


// Constraints
// x <= 100000000000000000


// Output Format
// Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.


// Sample Input
// 4545
// Sample Output
// 4444
// Explanation
// There are many numbers form after inverting the digit. For minimum number, check if inverting digit is less than or greater than the original digit. If it is less, then invert it otherwise leave it.


// #include<bits/stdc++.h>
// using namespace std;

// int main() {
// 	string x;
// 	cin >> x;
// 	bool flag = false;
// 	for (int i = 0; i < x.length(); i++) {
// 		if (i == 0 && ((x[i] - '0') == 9) ) {
// 			flag = true;
// 			continue;
// 		}
// 		if ( (x[i] - '0' ) >= 5 ) {
// 			x[i] = (9 - (x[i] - '0')) - '0';
// 		}
// 	}
// 	cout << x << endl;
// 	return 0;
// }

#include<iostream>
using namespace std;
int main() {
	long long int num, n;
	cin >> num;
	n = num;
	long long int ans = 0;
	long long int mult = 1;
	while (n != 0) {

		long long int rem = n % 10;

		if (rem >= 5) {

			if (rem == 9 && (n / 10) == 0) {
				//do nothing
			} else {
				rem = 9 - rem;
			}
		}
		ans += rem * mult;
		mult *= 10;
		n /= 10;
	}
	cout << ans;
	return 0;
}

