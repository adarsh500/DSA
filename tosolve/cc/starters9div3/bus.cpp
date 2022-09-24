#include <iostream>
#include <math.h>
using namespace std;

#define ll long long int

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, q, res = 1, count = 0;
		cin >> n >> m >> q;
		int inBus[100001] = {0};
		for (int i = 0; i < q; i++) {
			char sign;
			int person;
			cin >> sign >> person;
			
			if (sign == '+') {
				inBus[person]++;
				count++;
				if (count > m) {
					res = 0;
				}
			} else {
				if(inBus[person] == 0){
					res = 0;
				} else{
					inBus[person] = 0;
					count--;
				}
			}
		}
		if (res == 0){
			cout << "Inconsistent" << endl;
		} else {
			cout << "Consistent" << endl;
		}
	}
}