#include <iostream>
#include <cstring>
using namespace std;

void moveXToEnd(string str, int i){

	if (i == str.length()){
		return;
	}

	if (str[i] != 'x'){
		cout << str[i];
	}
	moveXToEnd(str, i + 1);
	if (str[i] == 'x'){
		cout << str[i];
	}

}

void moveXToEnd1(string str, int i){
	if (i == 0){
		cout << str;
		return;
	}

	if (str[i] == 'x'){
		int k = i;
		while (str[k] != '\0' and str[k + 1] != '\0'){
			swap(str[k], str[k + 1]);
			k++;
		}
	}

	moveXToEnd1(str, i - 1);
}

int main(){
	string str;
	cin >> str;

	// moveXToEnd1(str, 0);
	moveXToEnd1(str, str.length());
}