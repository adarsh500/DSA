// #include <iostream>
// using namespace std;

// string table[] = { " ", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx", "yz" };

// void printKeypadCodes(string str, int i, string output, int count){
// 	int count2 = 0;
// 	int ch = str[i] - '0';
// 	if (i == str.length()){
// 		output[i] = '\0';
// 		cout << output << " ";
// 	}


// 	for (int j = 0; j < table[ch].length(); j++){
// 		printKeypadCodes(str, i + 1, output + table[ch][j], count * table[ch].length());
// 	}
// }

// int main(){
// 	string str;
// 	cin >> str;

// 	printKeypadCodes(str, 0, "", 1);

// }
#include <iostream>
using namespace std;

string table[] = { " ", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx", "yz" };

void printKeypadCodes(string str, int i, string output){
	int ch = str[i] - '0';
	if (i == str.length()){
		output[i] = '\0';
		cout << output << " ";
	}


	for (int j = 0; j < table[ch].length(); j++){
		printKeypadCodes(str, i + 1, output + table[ch][j]);
	}
}

int countCodes(string str, int i, int count){

	int ch = str[i] - '0';
	if (i == str.length()){
		return count;
	}

	return countCodes(str, i + 1, count * table[ch].length());
}

int main(){
	string str;
	cin >> str;

	printKeypadCodes(str, 0, "");
	cout << endl << countCodes(str, 0, 1) << endl;

}