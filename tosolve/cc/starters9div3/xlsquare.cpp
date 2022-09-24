#include <iostream>
#include <math.h>
using namespace std;

#define ll long long int

int main(){
	int t;
	cin >> t;
	while (t--){
		ll n, a, maxSquare;
		cin >> n >> a;

		maxSquare = sqrt(n);
		cout << (maxSquare * a) << endl;
	}
}