#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int a, b, k, count = 0;
	cin >> a >> b >> k;


	for (int i = 1; i <= min(a, b); i++){
		if (a % i == 0 || b % i == 0){
			count++;
			if (count == k){
				cout << i << endl;
				break;
			}
		}
	}
}