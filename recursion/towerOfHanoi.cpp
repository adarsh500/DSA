#include <iostream>
using namespace std;


void towerOfHanoi(int n, string start, string end, string aux){
	if (n == 0){
		return;
	}

	towerOfHanoi(n-1, start, aux, end);
	cout << "Moving ring " << n << " from " << start << " to " << end << endl;
	towerOfHanoi(n-1, aux, end, start);
}

int main(){
	int n;
	cin >> n;


	towerOfHanoi(n, "A", "B", "C");
}