#include <iostream>
using namespace std;

int main(){
	int x, y;
	cin >> x >> y;

	int ans = 0, res = 0;
	for (int i = x; i < y; i++){
		for(int j = i + 1; j <= y; j++){
			ans = i ^ j;
			res = max(res, ans);
		}
	}

	cout << res << endl;
}