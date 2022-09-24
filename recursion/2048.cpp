//basically convert number to spellings

#include <iostream>
using namespace std;

char word[][10] {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void words(int n){
	if (n == 0){
		return;
	}

	int lastDigit = n % 10;
	words(n/10);
	cout << word[lastDigit] << " ";
}

int main(){


	int n;
	cin >> n;

	words(n);
}