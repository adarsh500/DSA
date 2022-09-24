#include<iostream>
using namespace std;


// int rainWaterHarvesting(int arr[], int n){
// 	//Naive approach
// 	int count = 0;

// 	for(int i = 1; i < n - 1 ; i++){

// 		//searches for the max number on the left side of arr[i]
// 		int left = arr[i];
// 		for (int j = 0; j < i; j++){
// 			left = max(left, arr[j]);
// 		}

// 		//searches for the max number on the right side of arr[i]
// 		int right = arr[i];
// 		for (int k = i + 1; k < n; k++){
// 			right = max(right, arr[k]);
// 		}

// 		//since the minimum of left and right determine the amount of
// 		//water stored, hence this <min(left, right)> and we also have
// 		//to subtract the 
// 		count += min(left, right) - arr[i];
// 	}
// 	return count;
// }

// int main(){
// 	int n, count;
// 	cin >> n;
// 	int arr[10000];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}

// 	count = rainWaterHarvesting(arr, n);

// 	cout << count;
// 	return 0;
// }

int arr[1000000], l[1000000], r[1000000];
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    l[0] = arr[0];
    r[n - 1] = arr[n - 1];
    for (i = 1; i < n; i++)
    {
        l[i] = max(l[i - 1], arr[i]);
    }
    for (i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], arr[i]);
    }
    int water = 0;
    for (i = 0; i < n; i++)
    {
        water += (min(l[i], r[i]) - arr[i]);
    }
    cout << water;

    return 0;
}