#include <iostream>
using namespace std;

bool pathExixts(char board[][11], int soln [][11], int i, int j, int n, int m){
	
	if (i == n && j == m){
		//path found
		soln[i][j] = 1;
		//print pattern
		for (int a = 0; a <= n; a++){
			for (int b = 0; b <= m; b++){
				cout << soln[a][b] << " ";
			}
			cout << endl;
		}
		return true;
	}

	if (i > n || j > m || i < 0 || j < 0){
		return false;
	}

	if (board[i][j] == 'X'){
		return false;
	}

	if (soln[i][j] == 1){
		return false;
	}

	//assume
	soln[i][j] = 1;
	bool up = false, down = false, left = false, right = false;


	down = pathExixts(board, soln, i + 1, j, n, m);

	if (!down){
		right = pathExixts(board, soln, i, j + 1, n, m);	
	}

	if (!right and !down){
		up = pathExixts(board, soln, i - 1, j, n, m);
	}

	if (!right and !down and !up){
		left = pathExixts(board, soln, i, j - 1, n, m);
	}


	if (up || right || down || left){
		return true;
	} 

	soln[i][j] = 0;

	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;

	char board[n][11];
	int soln[11][11] = {0};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}

	bool ans = pathExixts(board, soln, 0, 0, n - 1, m - 1);
	if (ans == false){
		cout<<"NO PATH FOUND";
	}

}