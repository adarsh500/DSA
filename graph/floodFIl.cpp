#include <bits/stdc++.h>
using namespace std;


// 12 28
// ..#######..........#######..
// ..##...#####...#####....###.
// .##......#########.......##.
// .##......................##.
// .##......................##.
// .##......................##.
// .###....................##..
// ..###..................##...
// ...##................###....
// ....##.............###......
// ....####..........###.......
// .....###############........

int row, col;
//this stores the directions W, N, E, S; 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void printMatrix(char input[][50]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << input[i][j];
		}
		cout << endl;
	}
}

void floodFill(char input[][50], int i, int j, char ch, char color){
	if (i < 0 or j < 0 or i >= row or j >= col){
		return;
	}

	if (input[i][j] != ch){
		return;
	}

	input[i][j] = color;

	for(int k = 0; k < 4; k++){
		floodFill(input, i + dx[k], j + dy[k], ch, color);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> row >> col;
	char input[50][50];
	for(int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cin >> input[i][j];
		}
	}

	floodFill(input, 7, 10, '.', '*');
	printMatrix(input);

}