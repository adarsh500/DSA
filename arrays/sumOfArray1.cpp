#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void arraySum(int arr1[], int s1, int arr2[], int s2, int output[]) {
	int i = s1 - 1, j = s2 - 1, k = s1, carry = 0, sum = 0;
	while (j >= 0)
	{
		sum = arr1[i] + arr2[j] + carry;
		output[k] = (sum % 10);
		carry = sum / 10;
		output[0] = carry;
		k--;
		i--;
		j--;
	}
	while (i >= 0)
	{
		sum = arr1[i] + carry;
		output[k] = (sum % 10);
		carry = sum / 10;
		output[0] = carry;
		i--;
		k--;
	}
}

int main() {
	int s1, s2;
	cin >> s1;
	int arr1[s1];
	for (int i = 0; i < s1; i++) {
		cin >> arr1[i];
	}

	cin >> s2;
	int arr2[s2];
	for (int i = 0; i < s2; i++) {
		cin >> arr2[i];
	}

	int maximum = max(s1, s2) + 1;
	int output[maximum];

	if (s1 > s2) {
		arraySum(arr1, s1, arr2, s2, output);
	} else {
		arraySum(arr2, s2, arr1, s1, output);
	}


	if(output[0] > 0){
		cout << output[0] << ", ";
	}
	for (int i = 1; i < maximum; ++i){
		cout << output[i] << ", ";
	}
	cout << "END";
}