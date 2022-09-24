#include <iostream>
using namespace std;


bool isSafeToPlace(int board[][20], int i, int j, int n) {
	for (int row = 0; row < i; row++) {
		if (board[row][j] == 1) {
			return false;
		}
	}

	int x = i, y = j;
	//checks for left diagonal
	while (x >= 0 and y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}


	x = i, y = j;
	//checks for right diagonal
	while (x >= 0 and y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	return true;
}


int permute(int board[][20], int i, int n, int cnt) {
	//base case
	if (i == n) {
		return 1;
	}

	//recursive case
	int count = 0;
	for (int j = 0; j < n; j++) {

		if (isSafeToPlace(board, i, j, n)) {
			board[i][j] = 1;
			count += permute(board, i + 1, n, cnt);

			//backtrack
			//means i and j are not in the right position
			//assumption is wrong
			board[i][j] = 0;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;

	int board[20][20] = {0};
	cout << permute(board, 0, n, 0) << endl;
}