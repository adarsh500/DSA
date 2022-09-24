#include <iostream>
using namespace std;

void parenthesesPermutations(int n, string output, int i, int openCount, int closeCount){
	if (i == (2*n)){
		cout << output << endl;
		return;
	}


	if (closeCount < openCount){
		parenthesesPermutations(n, output + ")", i + 1, openCount, closeCount + 1);
	}
	if (openCount < n){
		parenthesesPermutations(n, output + "(", i + 1, openCount + 1, closeCount);
	}
	
	
	return;
}

int main(){
	int n;
	cin >> n;

	parenthesesPermutations(n, "", 0, 0, 0);
}