#include <iostream>
using namespace std;

#define ll long long int

int gcd(int a, int b){
	while (a != b){
		(a > b) ? (a -= b) : (b -= a);
	}
	return a;
}

int main(){
	ll a, b;
	cin >> a >> b;

	int lcm = (a * b) / gcd(a, b);
	cout << lcm << endl;
}