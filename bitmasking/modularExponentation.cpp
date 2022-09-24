#include <iostream>
using namespace std;

#define ll long long int

int exponentation(ll a, unsigned int b, int c){
	ll res = 1;
	if (a % c == 0){
		return 0;
	}
	while(b > 0){
		if (b&1){
			res = (res * a)%c;
		}
		b = b>>1;
		a = (a * a) % c;
	}
	return res;
}

int main(){
	ll a;
	unsigned int b;
	int c;
	cin >> a >> b >> c;
	cout << exponentation(a, b, c) << endl;
	return 0;
}