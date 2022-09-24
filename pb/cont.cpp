#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n, sum = 0;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int left = 0, right = 1;
	while(left < right and right < n){

		int term = arr[right] - arr[left];
		sum += pow(term, 2);
		
		if (right == n - 1){
			left++;
			right = left + 1;
		} else {
			right++;
		}
	}




	cout << sum << endl;
}
