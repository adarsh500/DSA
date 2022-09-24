#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int submatrixQuery(int arr[][10], int n, int m, int tli, int tlj, int bri, int brj) {
	int sum = 0;
	sum = arr[bri][brj] - arr[tli - 1][brj] - arr[bri][tlj - 1] + arr[tli - 1][tlj - 1];
	return sum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int arr[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		int tli, tlj, bri, brj;
		cin >> tli >> tlj >> bri >> brj;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				arr[i][j] += arr[i][j - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				arr[j][i] += arr[j - 1][i];
			}
		}

		int sum = arr[bri][brj] - arr[tli - 1][brj] - arr[bri][tlj - 1] + arr[tli - 1][tlj - 1]; 

		cout << sum << endl;
	}
}