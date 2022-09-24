//problem that counts all the possible solutions of placing queen
//time complexity is 1 / n of previous time complexity	
#include <iostream>
#include <bitset>
using namespace std;

bitset<30> column, diagonal1, diagonal2;

void solve(int row, int n, int &ans){
	if (row == n){
		ans++;
		return;
	}

	for (int c = 0; c < n; c++){
		if (!column[c] && !diagonal1[row - c + n - 1] && !diagonal2[row + c]){
			column[c] = diagonal1[row - c + n - 1] = diagonal2[row + c] = 1;
			solve(row + 1, n, ans);

			//backtrack
			column[c] = diagonal1[row - c + n - 1] = diagonal2[row + c] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;

	int ans = 0;
	solve(0, n, ans);
	cout << ans << endl;
}



//if you want to print the board use this :)

//problem that counts all the possible solutions of placing queen
//time complexity is 1 / n of previous time complexity	
// #include <iostream>
// #include <bitset>
// using namespace std;

// bitset<30> column, diagonal1, diagonal2;

// void solve(int row, int n, int &ans, int board[][20]){
// 	if (row == n){
// 		for (int i = 0; i < n; i++){
// 			for (int j = 0; j < n; j++){
// 				cout << board[i][j] << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;
// 		ans++;
// 		return;
// 	}

// 	for (int c = 0; c < n; c++){
// 		if (!column[c] && !diagonal1[row - c + n - 1] && !diagonal2[row + c]){
// 			column[c] = diagonal1[row - c + n - 1] = diagonal2[row + c] = board[row][c] = 1;
// 			solve(row + 1, n, ans, board);

// 			//backtrack
// 			column[c] = diagonal1[row - c + n - 1] = diagonal2[row + c] = board[row][c] = 0;
// 		}
// 	}
// }

// int main(){
// 	int n;
// 	cin >> n;

// 	int ans = 0;
// 	int board[20][20] = {0};
// 	solve(0, n, ans, board);
// 	// cout << ans << endl;
// }
