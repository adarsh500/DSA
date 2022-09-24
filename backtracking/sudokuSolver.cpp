#include <iostream>
#include <cmath>
using namespace std;

bool isSafeToPlace(int board[][9], int n, int i, int j, int num) {

	//now we need to find the start index of the subgrid that
	//our i, j is at. if we div i and j by 3, we get the pos
	//of subgrid and if we *3 to it, then we get the start index

	for (int k = 0; k < n; k++) {
		if (board[k][j] == num || board[i][k] == num) {
			return false;
		}
	}

	int subgridSize = sqrt(n);
	int startX = (i / subgridSize) * subgridSize;
	int startY = (j / subgridSize) * subgridSize;

	for (int a = startX; a < startX + subgridSize; a++) {
		for (int b = startY; b < startY + subgridSize; b++) {
			if (board[a][b] == num) {
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int board[][9], int n, int i, int j) {
	if (i == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}

	if (j == n) {
		return solveSudoku(board, n, i + 1, 0);
	}

	if (board[i][j] != 0) {
		return solveSudoku(board, n, i, j + 1);
	}

	//recursive case
	for (int num = 1; num <= 9; num++) {
		if (isSafeToPlace(board, n, i , j, num)) {
			//assume
			board[i][j] = num;
			bool canSolveNext = solveSudoku(board, n, i, j + 1);
			if (canSolveNext) {
				return true;
			}
		}
	}
	//backtracking
	board[i][j] = 0;

	return false;
}

int main() {
	int n;
	cin >> n;
	int board[9][9];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	solveSudoku(board, n, 0, 0);
}