#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate(string str, int i){
	int len = str.length(), count, k = i + 1;
	if (i == len){
		return;
	}
 
	cout << str[i];
	if (str[i] == str[i + 1]){
		count = 0;
		while(str[i] == str[k]){
			k++;
			count++;
		}
		removeDuplicate(str, i + count + 1);
	} else {
		removeDuplicate(str, i + 1);
	}
}

int main(){
	string str;
	cin >> str;
	removeDuplicate(str, 0);
}