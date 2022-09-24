#include <iostream>
#include <math.h>
using namespace std;

int RecursivePower(int n, int p)
{
    if(p==0)
        return 1;
    return n*RecursivePower(n,p-1);
}

int fastPower(int n, int p){
	if (p == 0){
		return 1;
	}
	if (p&1){
		return n * pow(fastPower(n, p/2), 2);
	} else {
		return pow(fastPower(n, p/2), 2);
	}
}

int main(){
	int a, n;
	cin >> a >> n;

	cout << fastPower(a, n) << endl;
	cout << RecursivePower(a, n) << endl;
	
}  