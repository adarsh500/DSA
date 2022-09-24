#include <iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printPossibleKeys(string input, int i, string output){
	int length = input.length();
	int ch = input[i] - '0';
	if (i == length){
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	for (int j = 0; j < table[ch].length(); j++){
		printPossibleKeys(input, i + 1, output + table[ch][j]);
	}

	return;
}


int main(){
	string input;
	cin >> input;


	printPossibleKeys(input, 0, "");
}