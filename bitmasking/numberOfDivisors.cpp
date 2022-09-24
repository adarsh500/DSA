#include <iostream>
#include <vector>
using namespace std;

void noOfDivisors(int n) {
	vector <pair<int , int> > factors;
	int count = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			count = 0;
			while (n % i == 0) {
				count++;
				n /= i;
			}
			factors.push_back(make_pair(i, count));
		}
	}
	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}

	int divisors = 1;
	for(int i = 0; i < factors.size(); i++){
		divisors *= (factors[i].second + 1);
	}
	cout << divisors << endl;
}

int main() {
	int n;
	cin >> n;
	noOfDivisors(n);
}