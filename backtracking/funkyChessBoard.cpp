#include <iostream>
using namespace std;

int cantVisit = 100;

void countMin(int board[][10], int KnightCanVisit[][10], int n){
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (KnightCanVisit[i][j] != 1 && board[i][j] == 1){
				count++;
			}
		}
	}
	cantVisit = min(cantVisit, count);
}

void knightMoves(int board[][10], int KnightCanVisit[][10], int i, int j, int n){

	if (i >= n || j >= n || i < 0 || j < 0){
		return;
	}

	if (board[i][j] == 0 || KnightCanVisit[i][j] == 1){
		return;
	}

	KnightCanVisit[i][j] = 1;
	countMin(board, KnightCanVisit, n);

	knightMoves(board, KnightCanVisit, i + 2, j + 1, n);
	knightMoves(board, KnightCanVisit, i + 2, j - 1, n);
	knightMoves(board, KnightCanVisit, i - 2, j + 1, n);
	knightMoves(board, KnightCanVisit, i - 2, j - 1, n);

	knightMoves(board, KnightCanVisit, i - 1, j + 2, n);
	knightMoves(board, KnightCanVisit, i + 1, j + 2, n);
	knightMoves(board, KnightCanVisit, i - 1, j - 2, n);
	knightMoves(board, KnightCanVisit, i + 1, j - 2, n);

	KnightCanVisit[i][j] = 0;
}

int main(){
	int n;
	cin >> n;

	int board[10][10];

	int KnightCanVisit[10][10] = {0};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	knightMoves(board, KnightCanVisit, 0, 0, n);
	cout << cantVisit << endl;
	return 0;
}