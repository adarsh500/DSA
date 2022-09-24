#include <iostream>
using namespace std;

int main(){
	int i = 0;
	int sum = 0;
	while(i < 100){
		sum += i;
		sum += i;
		i += 1;
	}
	cout << sum;
}