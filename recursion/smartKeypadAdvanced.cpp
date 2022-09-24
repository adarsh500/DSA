#include <iostream>
#include <string>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn[] = {
            "kartik", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void printPossibleKeys(string input, int i, string output){
	int length = input.length();
	int ch = input[i] - '0';
	if (i == length){
		output[i] = '\0';
		for (int idx = 0; idx < 11; idx++){
			size_t pos = searchIn[idx].find(output);
			if (pos != string::npos){
				cout << searchIn[idx] << endl;
			}
		}
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