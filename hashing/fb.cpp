#include <bits/stdc++.h>
using namespace std;

int main(){
	int counter3 = 0, counter5 = 0;
	for(int i = 0; i < 50; i++){
		if (counter3 == 3){
			cout << "fizz";
			counter3 = 0;
			continue;
		}

		if  (counter5 == 5){
			cout << "buzz";
			counter5 = 0;
			continue;
		} 

		// if (counter5 != 5 && counter3 != 3){
			cout << i;
			counter5++;
			counter3++;
		// }
		cout << endl;
	}
}