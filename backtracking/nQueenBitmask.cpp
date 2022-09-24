#include <iostream>
using namespace std;

int n;
int ans = 0, DONE;

//most optimized
void solve(int rowmask, int leftDiagonal, int rightDiagonal){
	if (rowmask == DONE){
		ans++;
		return;
	}

	int safe = DONE & ~(rowmask | leftDiagonal |rightDiagonal);
	while (safe){
		int p = safe & (-safe);
		safe = safe - p;
		solve(rowmask | p, (leftDiagonal | p) << 1, (rightDiagonal | p) >> 1);
	}
}

int main(){
	cin >> n;
	DONE = ((1 << n) - 1); 
	solve(0, 0, 0);
	cout << ans << endl;
}