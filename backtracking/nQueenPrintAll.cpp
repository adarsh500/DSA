#include <iostream>
using namespace std;

int count(int i){
	i++;
	return i;
}

bool isSafeToPlace(int board[][10], int i, int j, int n) {
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


bool permute(int board[][10], int i, int n, int cnt) {
	if (i == n) {

		// prints the output
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1) {
					cout << "Q";
				} else {
					cout << "-";
				}
			}
			cout << endl;
		}
		cout << endl;
		//here's the interesting part, if we do return true, then it will
		//print the first solution and exit code
		//however if we do return false, it will print all the possible outcomes
		// :)
		return false;
	}

	for (int j = 0; j < n; j++) {
		if (isSafeToPlace(board, i, j, n)) {
			board[i][j] = 1;

			bool canPlaceNextQueen = permute(board, i + 1, n, cnt);
			if (canPlaceNextQueen) {
				return true;
			}

			//backtrack
			//means i and j are not in the right position
			//assumption is wrong
			board[i][j] = 0;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	int board[10][10] = {0};
	permute(board, 0, n, 0);
}