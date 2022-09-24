#include <iostream>
using namespace std;

void generateBrackets(char *output, int n, int i, int openCount, int closeCount){
	if (i == 2 * n){
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	if (openCount < n){
		output[i] = '(';
		generateBrackets(output, n, i + 1, openCount + 1, closeCount);
	}

	if (closeCount < openCount){
		output[i] = ')';
		generateBrackets(output, n, i + 1, openCount, closeCount + 1);
	}

	return;
}

int main(){
	int n;
	cin >> n;

	char output[1000];
	generateBrackets(output, n, 0, 0, 0);
}