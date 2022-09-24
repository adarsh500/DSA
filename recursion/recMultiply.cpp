//NOTE: you cannot use the * sign;

#include <iostream>
using namespace std;

int multiply(int a, int n){
	if (n == 0){
		return 0;
	}
	return a + multiply(a, n - 1);
}

int main(){
	int a, n;
	cin >> a >> n;
	cout << multiply(a, n) << endl;
}