/*generally count sort is used when the range of array elements is small
Its complexity is O(N + range).

*/

#include <iostream>
#include <climits>
using namespace std;

int largest = -999999;

void countSort(int arr[], int n){
	int *freq = new int[largest + 1]{0};

	for (int i = 0; i < n; i++){
		freq[arr[i]]++;
	}

	int j = 0;
	for(int i = 0; i <= largest; i++){
		while(freq[i] > 0){
			arr[j++] = i;
			freq[i]--;
		}
	}
}



int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		largest = max(largest, arr[i]);
	}

	countSort(arr, n);

	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}	
}