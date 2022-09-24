#include <iostream>
using namespace std;

char map[][27] = {"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
void mappedStrings(string str, string op, int i){
	int len = str.length();
	if (i == len){
		cout << op << endl;
		return;
	}

	if (str[i] != '0'){
		int num = str[i] - '0';
		string c = map[num];
		mappedStrings(str, op+c, i + 1);
	}

	if (i < len - 1){
		int num2 = str[i] - '0';
		int num3 = str[i + 1] - '0';
		int num4 = (num2 * 10) + num3;
		if (num4 <= 26){
			string c1 = map[num4];
			mappedStrings(str, op+c1, i + 2);
		}
	}
}

int main(){
	string str;
	cin >> str;

	mappedStrings(str, "", 0);
}