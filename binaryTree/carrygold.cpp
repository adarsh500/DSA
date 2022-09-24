#include <iostream>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >> y;
		if ((n + 1) * y >= x){
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
		return 0;
	}

}