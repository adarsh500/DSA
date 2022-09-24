#include <iostream>
#include <cstring>
using namespace std;

//the answer to this question resembles that of fibo series.
//answer of n length of string = (n + 2)th term of fibo

int fibo(int n){
	if (n <= 1){
		return n;
	}
	return fibo(n- 1) + fibo(n - 2);
}


//recursive method

int main(){
	int n;
	cin >> n;

	cout << fibo(n + 2) << endl;
}