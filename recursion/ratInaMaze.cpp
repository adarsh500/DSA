#include <iostream>
using namespace std;

bool ratinaMaze(char maze[][1000], int soln[][1000], int i, int j, int n, int m) {
	bool down = false;
	if (i == n and j == m) {
		soln[i][j] = 1;

		//print the path
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		// cout << endl;
		return true;
	}

	if (i > n || j > m) {
		return false;
	}

	if (maze[i][j] == 'X') {
		return false;
	}

	//assume that the current cell is a correct path
	soln[i][j] = 1;
	//you have 2 choices, either you can go down or right of the current cell
	bool right = ratinaMaze(maze, soln, i, j + 1, n, m);


	if (right){
		return true;
	} else {
		down = ratinaMaze(maze, soln, i + 1, j, n, m);
		if (down){
			return true;
		}
	}

	//backtracking
	//we return back to the current cell if both the options are false or if 
	//we want to check for another possible path
	soln[i][j] = 0;


	return false;
}

int main() {
	char maze[1000][1000];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> maze[i][j];
		}
	}

	int soln[1000][1000] = {0};


	bool ans = ratinaMaze(maze, soln, 0, 0, n - 1, m - 1);

	if (ans == false) {
		cout << "-1" << endl;
	}
}