// You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.


// Input Format
// First line contains number of test cases, T. Next T lines contains integers, n and k.


// Constraints
// 1<=T<=10
// 1<=N<=10^15
// 1<=K<=10^4


// Output Format
// Output the integer x


// Sample Input
// 2
// 10000 1
// 1000000000000000 10
// Sample Output
// 10000
// 31
// Explanation
// For the first test case, for x=10000, 10000^1=10000=n


#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long int n, k;
		cin >> n >> k;
		//x^k <= n
		//log10(x) <= log10(n) / k
		long long int x = pow(10, (log10(n) / k));
		cout << x << endl;
	}
	return 0;
}